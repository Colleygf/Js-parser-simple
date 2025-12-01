%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "ast.h"
#include "parser_types.h"

// 声明函数
int yylex(void);
void yyerror(ScannerState *scanner, const char *s);

// 声明全局变量
extern ScannerState *global_scanner;

// 全局 AST 根节点
ASTNode* ast_root = NULL;

%}

%parse-param {ScannerState *scanner}

// 定义语义值类型
%union {
    char* str;
    ASTNode* node;
    int int_val;
    ArgList* arg_list;
    ParamList* param_list;
    ClassElementList* class_element_list;
    MethodDefinition* method_def;
    PropertyDefinition* prop_def;
    PropertyList* property_list;
}

%token IF ELSE WHILE FOR FUNCTION VAR LET CONST RETURN BREAK CONTINUE
%token TRUE FALSE NULL_LITERAL UNDEFINED
%token CLASS NEW THIS SUPER STATIC EXTENDS CONSTRUCTOR
%token NEWLINE
%token <str> IDENTIFIER NUMBER STRING
%token PLUS MINUS STAR SLASH PERCENT
%token EQUALS EQ_EQ NOT_EQ STRICT_EQ STRICT_NOT_EQ
%token LT LE GT GE BANG AND OR
%token PLUS_PLUS MINUS_MINUS PLUS_EQ MINUS_EQ STAR_EQ SLASH_EQ
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA DOT COLON QUESTION
%token DOT_DOT_DOT ARROW
%token <str> TEMPLATE_STRING
%token <node> REGEXP_LITERAL
%token SWITCH CASE DEFAULT TRY CATCH FINALLY
%token ERROR

/* 重新设计的优先级和结合性 */
%nonassoc POSTFIX          /* 后缀运算符 */
%left COMMA
%right ASSIGNMENT          /* 赋值运算符 */
%right QUESTION COLON      /* 条件运算符 */
%left OR
%left AND
%left BITWISE_OR
%left BITWISE_XOR
%left BITWISE_AND
%left EQUALITY             /* ==, !=, ===, !== */
%left RELATIONAL           /* <, >, <=, >= */
%left SHIFT
%left ADDITIVE             /* +, - */
%left MULTIPLICATIVE       /* *, /, % */
%right EXPONENTIAL
%right UNARY               /* 一元运算符 +, -, !, ++, -- */
%left DOT LBRACKET
%nonassoc CALL             /* 函数调用和成员访问 */

/* 为特定运算符分配优先级 */
%right PRE_INC PRE_DEC     /* 前缀 ++ -- */
%left POST_INC POST_DEC    /* 后缀 ++ -- */

%type <node> program statements statement
%type <node> variable_declaration variable_declaration_no_semi optional_initializer
%type <node> expression_statement empty_statement block_statement
%type <node> if_statement while_statement for_statement
%type <node> function_declaration return_statement break_statement continue_statement
%type <node> expression assignment_expression conditional_expression
%type <node> logical_or_expression logical_and_expression equality_expression
%type <node> relational_expression additive_expression multiplicative_expression
%type <node> unary_expression postfix_expression primary_expression
%type <node> call_expression member_expression new_expression
%type <node> expression_opt for_init for_cond for_iter
%type <param_list> parameter_list_opt parameter_list
%type <node> asi_semicolon
%type <arg_list> argument_list_opt argument_list
%type <node> function_expression
%type <node> switch_statement try_statement

// 添加类和对象相关的类型声明
%type <node> class_declaration class_body class_element
%type <node> class_extends_opt
%type <int_val> static_opt
%type <method_def> method_definition
%type <prop_def> property_definition
%type <class_element_list> class_element_list_opt class_element_list
%type <node> left_hand_side left_hand_side_expression

// 数组相关
%type <node> array_literal
%type <arg_list> array_element_list_opt array_element_list

// 新增现代语法特性
%type <node> object_literal property arrow_function spread_element
%type <property_list> property_list_opt property_list

%start program

%%

program
    : statements
    {
        $$ = $1;
        ast_root = $$;
        printf("PARSER: Successfully parsed program and built AST\n");
    }
    ;

statements
    : /* empty */
    {
        ASTNode** stmts = malloc(sizeof(ASTNode*) * 0);
        $$ = create_program(stmts, 0);
    }
    | statement
    {
        ASTNode** stmts = malloc(sizeof(ASTNode*) * 1);
        stmts[0] = $1;
        $$ = create_program(stmts, 1);
    }
    | statements statement
    {
        int old_count = $1->data.program.statement_count;
        ASTNode** new_stmts = malloc(sizeof(ASTNode*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_stmts[i] = $1->data.program.statements[i];
        }
        new_stmts[old_count] = $2;
        
        free($1->data.program.statements);
        $1->data.program.statements = new_stmts;
        $1->data.program.statement_count = old_count + 1;
        $$ = $1;
    }
    ;

statement
    : variable_declaration { $$ = $1; }
    | expression_statement { $$ = $1; }
    | if_statement { $$ = $1; }
    | while_statement { $$ = $1; }
    | for_statement { $$ = $1; }
    | function_declaration { $$ = $1; }
    | class_declaration { $$ = $1; }
    | return_statement { $$ = $1; }
    | break_statement { $$ = $1; }
    | continue_statement { $$ = $1; }
    | block_statement { $$ = $1; }
    | empty_statement { $$ = $1; }
    | switch_statement { $$ = $1; }
    | try_statement { $$ = $1; }
    ;

/* 类声明语法规则 */
class_declaration
    : CLASS IDENTIFIER class_extends_opt class_body asi_semicolon
    {
        $$ = create_class_declaration($2, $3, $4);
        free($2);
    }
    ;

class_extends_opt
    : /* empty */ { $$ = NULL; }
    | EXTENDS IDENTIFIER { $$ = create_identifier($2); free($2); }
    ;

class_body
    : LBRACE class_element_list_opt RBRACE
    {
        $$ = create_class_body($2->elements, $2->element_count);
        free($2);
    }
    ;

class_element_list_opt
    : /* empty */
    {
        $$ = malloc(sizeof(ClassElementList));
        $$->elements = malloc(sizeof(ASTNode*) * 0);
        $$->element_count = 0;
    }
    | class_element_list
    {
        $$ = $1;
    }
    ;

class_element_list
    : class_element
    {
        $$ = malloc(sizeof(ClassElementList));
        $$->elements = malloc(sizeof(ASTNode*) * 1);
        $$->elements[0] = $1;
        $$->element_count = 1;
    }
    | class_element_list class_element
    {
        int old_count = $1->element_count;
        ASTNode** new_elements = malloc(sizeof(ASTNode*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_elements[i] = $1->elements[i];
        }
        new_elements[old_count] = $2;
        
        free($1->elements);
        $1->elements = new_elements;
        $1->element_count = old_count + 1;
        $$ = $1;
    }
    ;

class_element
    : static_opt method_definition
    {
        $$ = create_class_method($2->kind, $2->key, $2->value, $1);
        free($2->key);
        free($2);
    }
    | static_opt property_definition SEMICOLON
    {
        $$ = create_class_property($2->key, $2->value, $1);
        free($2->key);
        free($2);
    }
    ;

static_opt
    : /* empty */ { $$ = 0; }
    | STATIC { $$ = 1; }
    ;

method_definition
    : CONSTRUCTOR LPAREN parameter_list_opt RPAREN block_statement
    {
        $$ = malloc(sizeof(MethodDefinition));
        $$->kind = strdup("constructor");
        $$->key = strdup("constructor");
        $$->value = create_function_declaration("constructor", $3->parameters, $3->parameter_count, $5);
        free($3);
    }
    | IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement
    {
        $$ = malloc(sizeof(MethodDefinition));
        $$->kind = strdup("method");
        $$->key = strdup($1);
        $$->value = create_function_declaration($1, $3->parameters, $3->parameter_count, $5);
        free($1);
        free($3);
    }
    ;

property_definition
    : IDENTIFIER
    {
        $$ = malloc(sizeof(PropertyDefinition));
        $$->key = strdup($1);
        $$->value = NULL;
        free($1);
    }
    | IDENTIFIER EQUALS expression
    {
        $$ = malloc(sizeof(PropertyDefinition));
        $$->key = strdup($1);
        $$->value = $3;
        free($1);
    }
    ;

/* 变量声明 */
variable_declaration
    : VAR IDENTIFIER optional_initializer asi_semicolon
    {
        $$ = create_variable_declaration("var", $2, $3);
        free($2);
    }
    | LET IDENTIFIER optional_initializer asi_semicolon
    {
        $$ = create_variable_declaration("let", $2, $3);
        free($2);
    }
    | CONST IDENTIFIER optional_initializer asi_semicolon
    {
        $$ = create_variable_declaration("const", $2, $3);
        free($2);
    }
    ;

optional_initializer
    : /* empty */ { $$ = NULL; }
    | EQUALS expression { $$ = $2; }
    ;

/* 表达式语句 */
expression_statement
    : expression asi_semicolon
    {
        $$ = create_expression_statement($1);
    }
    ;

/* ASI分号处理 */
asi_semicolon
    : SEMICOLON { $$ = NULL; }
    | NEWLINE { $$ = NULL; printf("PARSER: ASI - Automatically inserted semicolon\n"); } 
    | /* empty */ { $$ = NULL; printf("PARSER: ASI - Automatically inserted semicolon\n"); }  
    ;

/* 空语句 */
empty_statement
    : SEMICOLON
    {
        $$ = create_empty_statement();
    }
    ;

/* 块语句 */
block_statement
    : LBRACE statements RBRACE
    {
        $$ = create_block_statement($2->data.program.statements, $2->data.program.statement_count);
        free($2);
    }
    | LBRACE RBRACE
    {
        ASTNode** body = malloc(sizeof(ASTNode*) * 0);
        $$ = create_block_statement(body, 0);
    }
    ;

/* if 语句 */
if_statement
    : IF LPAREN expression RPAREN statement
    {
        $$ = create_if_statement($3, $5, NULL);
    }
    | IF LPAREN expression RPAREN statement ELSE statement
    {
        $$ = create_if_statement($3, $5, $7);
    }
    ;

/* while 语句 */
while_statement
    : WHILE LPAREN expression RPAREN statement
    {
        $$ = create_while_statement($3, $5);
    }
    ;

/* for 语句 */
for_statement
    : FOR LPAREN for_init SEMICOLON for_cond SEMICOLON for_iter RPAREN statement
    {
        $$ = create_for_statement($3, $5, $7, $9);
    }
    ;

for_init
    : /* empty */ { $$ = NULL; }
    | variable_declaration_no_semi { $$ = $1; }
    | expression { $$ = $1; }
    ;

for_cond
    : /* empty */ { $$ = NULL; }
    | expression { $$ = $1; }
    ;

for_iter
    : /* empty */ { $$ = NULL; }
    | expression { $$ = $1; }
    ;

variable_declaration_no_semi
    : VAR IDENTIFIER optional_initializer
    {
        $$ = create_variable_declaration("var", $2, $3);
        free($2);
    }
    | LET IDENTIFIER optional_initializer
    {
        $$ = create_variable_declaration("let", $2, $3);
        free($2);
    }
    | CONST IDENTIFIER optional_initializer
    {
        $$ = create_variable_declaration("const", $2, $3);
        free($2);
    }
    ;

/* 简单的 switch 语句规则 */
switch_statement
    : SWITCH LPAREN expression RPAREN block_statement
    {
        $$ = create_switch_statement($3, $5);
    }
    ;

/* 简单的 try 语句规则 */
try_statement
    : TRY block_statement CATCH LPAREN IDENTIFIER RPAREN block_statement
    {
        // 简化处理：将 catch 参数忽略，只使用 catch 块
        $$ = create_try_statement($2, $7, NULL);
        free($5);
    }
    | TRY block_statement CATCH LPAREN IDENTIFIER RPAREN block_statement FINALLY block_statement
    {
        $$ = create_try_statement($2, $7, $9);
        free($5);
    }
    | TRY block_statement FINALLY block_statement
    {
        $$ = create_try_statement($2, NULL, $4);
    }
    ;

/* 函数声明 */
function_declaration
    : FUNCTION IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement
    {
        $$ = create_function_declaration($2, $4->parameters, $4->parameter_count, $6);
        free($2);
        free($4);
    }
    ;

parameter_list_opt
    : /* empty */
    {
        $$ = malloc(sizeof(ParamList));
        $$->parameters = malloc(sizeof(char*) * 0);
        $$->parameter_count = 0;
    }
    | parameter_list
    {
        $$ = $1;
    }
    ;

parameter_list
    : IDENTIFIER
    {
        $$ = malloc(sizeof(ParamList));
        $$->parameters = malloc(sizeof(char*) * 1);
        $$->parameters[0] = $1;
        $$->parameter_count = 1;
    }
    | parameter_list COMMA IDENTIFIER
    {
        int old_count = $1->parameter_count;
        char** new_params = malloc(sizeof(char*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_params[i] = $1->parameters[i];
        }
        new_params[old_count] = $3;
        
        free($1->parameters);
        $1->parameters = new_params;
        $1->parameter_count = old_count + 1;
        $$ = $1;
    }
    ;

/* 返回语句 */
return_statement
    : RETURN expression_opt asi_semicolon
    {
        $$ = create_return_statement($2);
    }
    ;

function_expression
    : FUNCTION IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement
    {
        $$ = create_function_expression($2, $4->parameters, $4->parameter_count, $6);
        free($2);
        free($4);
    }
    | FUNCTION LPAREN parameter_list_opt RPAREN block_statement
    {
        $$ = create_function_expression(NULL, $3->parameters, $3->parameter_count, $5);
        free($3);
    }
    ;

/* break 和 continue 语句 */
break_statement
    : BREAK asi_semicolon
    {
        $$ = create_break_statement();
    }
    ;

continue_statement
    : CONTINUE asi_semicolon
    {
        $$ = create_continue_statement();
    }
    ;

expression_opt
    : /* empty */ { $$ = NULL; }
    | expression { $$ = $1; }
    ;

/* 表达式层次结构 */
expression
    : assignment_expression { $$ = $1; }
    ;

assignment_expression
    : conditional_expression { $$ = $1; }
    | left_hand_side EQUALS assignment_expression
    {
        $$ = create_assignment_expression(OP_ASSIGN, $1, $3);
    }
    | left_hand_side PLUS_EQ assignment_expression
    {
        $$ = create_assignment_expression(OP_ADD_ASSIGN, $1, $3);
    }
    | left_hand_side MINUS_EQ assignment_expression
    {
        $$ = create_assignment_expression(OP_SUB_ASSIGN, $1, $3);
    }
    | left_hand_side STAR_EQ assignment_expression
    {
        $$ = create_assignment_expression(OP_MUL_ASSIGN, $1, $3);
    }
    | left_hand_side SLASH_EQ assignment_expression
    {
        $$ = create_assignment_expression(OP_DIV_ASSIGN, $1, $3);
    }
    ;

// 扩展 left_hand_side 规则
left_hand_side
    : IDENTIFIER { $$ = create_identifier($1); free($1); }
    | member_expression { $$ = $1; }
    | call_expression { $$ = $1; }
    | array_literal { $$ = $1; }
    | object_literal { $$ = $1; }
    ;

conditional_expression
    : logical_or_expression { $$ = $1; }
    | logical_or_expression QUESTION expression COLON conditional_expression
    {
        $$ = create_conditional_expression($1, $3, $5);
    }
    ;

logical_or_expression
    : logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression
    {
        $$ = create_binary_expression(OP_OR, $1, $3);
    }
    ;

logical_and_expression
    : equality_expression { $$ = $1; }
    | logical_and_expression AND equality_expression
    {
        $$ = create_binary_expression(OP_AND, $1, $3);
    }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQ_EQ relational_expression
    {
        $$ = create_binary_expression(OP_EQ, $1, $3);
    }
    | equality_expression NOT_EQ relational_expression
    {
        $$ = create_binary_expression(OP_NEQ, $1, $3);
    }
    | equality_expression STRICT_EQ relational_expression
    {
        $$ = create_binary_expression(OP_STRICT_EQ, $1, $3);
    }
    | equality_expression STRICT_NOT_EQ relational_expression
    {
        $$ = create_binary_expression(OP_STRICT_NEQ, $1, $3);
    }
    ;

relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression LT additive_expression
    {
        $$ = create_binary_expression(OP_LT, $1, $3);
    }
    | relational_expression LE additive_expression
    {
        $$ = create_binary_expression(OP_LE, $1, $3);
    }
    | relational_expression GT additive_expression
    {
        $$ = create_binary_expression(OP_GT, $1, $3);
    }
    | relational_expression GE additive_expression
    {
        $$ = create_binary_expression(OP_GE, $1, $3);
    }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression PLUS multiplicative_expression
    {
        $$ = create_binary_expression(OP_ADD, $1, $3);
    }
    | additive_expression MINUS multiplicative_expression
    {
        $$ = create_binary_expression(OP_SUB, $1, $3);
    }
    ;

multiplicative_expression
    : unary_expression { $$ = $1; }
    | multiplicative_expression STAR unary_expression
    {
        $$ = create_binary_expression(OP_MUL, $1, $3);
    }
    | multiplicative_expression SLASH unary_expression
    {
        $$ = create_binary_expression(OP_DIV, $1, $3);
    }
    | multiplicative_expression PERCENT unary_expression
    {
        $$ = create_binary_expression(OP_MOD, $1, $3);
    }
    ;

unary_expression
    : postfix_expression { $$ = $1; }
    | PLUS unary_expression
    {
        $$ = create_unary_expression(OP_ADD, $2);
    }
    | MINUS unary_expression
    {
        $$ = create_unary_expression(OP_SUB, $2);
    }
    | BANG unary_expression
    {
        $$ = create_unary_expression(OP_NOT, $2);
    }
    | PLUS_PLUS unary_expression
    {
        $$ = create_unary_expression(OP_PRE_INC, $2);
    }
    | MINUS_MINUS unary_expression
    {
        $$ = create_unary_expression(OP_PRE_DEC, $2);
    }
    ;

/* 重构 postfix_expression 以避免冲突 */
postfix_expression
    : left_hand_side_expression
    | postfix_expression PLUS_PLUS %prec POST_INC
    {
        $$ = create_unary_expression(OP_POST_INC, $1);
    }
    | postfix_expression MINUS_MINUS %prec POST_DEC
    {
        $$ = create_unary_expression(OP_POST_DEC, $1);
    }
    ;

left_hand_side_expression
    : call_expression
    | member_expression
    | new_expression
    ;

/* 简化 call_expression - 移除冗余规则 */
call_expression
    : member_expression LPAREN argument_list_opt RPAREN
    {
        $$ = create_call_expression($1, $3->arguments, $3->argument_count);
        free($3);
    }
    | call_expression LPAREN argument_list_opt RPAREN
    {
        $$ = create_call_expression($1, $3->arguments, $3->argument_count);
        free($3);
    }
    ;

/* 成员表达式 */
member_expression
    : primary_expression
    | member_expression DOT IDENTIFIER
    {
        $$ = create_member_expression($1, create_identifier($3), 0);
        free($3);
    }
    | member_expression LBRACKET expression RBRACKET
    {
        $$ = create_member_expression($1, $3, 1);
    }
    | call_expression DOT IDENTIFIER  // 新增：允许在调用后接成员访问
    {
        $$ = create_member_expression($1, create_identifier($3), 0);
        free($3);
    }
    | call_expression LBRACKET expression RBRACKET  // 新增：允许在调用后接计算成员访问
    {
        $$ = create_member_expression($1, $3, 1);
    }
    ;

/* new 表达式 */
new_expression
    : NEW member_expression LPAREN argument_list_opt RPAREN
    {
        $$ = create_new_expression($2, $4->arguments, $4->argument_count);
        free($4);
    }
    | NEW member_expression
    {
        $$ = create_new_expression($2, NULL, 0);
    }
    ;

primary_expression
    : IDENTIFIER { $$ = create_identifier($1); free($1); }
    | NUMBER { $$ = create_number($1); free($1); }
    | STRING { $$ = create_string($1); free($1); }
    | TEMPLATE_STRING { $$ = create_string($1); free($1); }
    | REGEXP_LITERAL { $$ = $1; }
    | TRUE { $$ = create_boolean(1); }
    | FALSE { $$ = create_boolean(0); }
    | NULL_LITERAL { $$ = create_null(); }
    | UNDEFINED { $$ = create_undefined(); }
    | THIS { $$ = create_this_expression(); }
    | SUPER { $$ = create_super_expression(); }
    | array_literal { $$ = $1; }
    | object_literal { $$ = $1; }
    | arrow_function { $$ = $1; }
    | function_expression { $$ = $1; }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

argument_list_opt
    : /* empty */
    {
        $$ = malloc(sizeof(ArgList));
        $$->arguments = malloc(sizeof(ASTNode*) * 0);
        $$->argument_count = 0;
    }
    | argument_list
    {
        $$ = $1;
    }
    ;

argument_list
    : expression
    {
        ArgList* list = malloc(sizeof(ArgList));
        list->arguments = malloc(sizeof(ASTNode*));
        list->arguments[0] = $1;
        list->argument_count = 1;
        $$ = list;
    }
    | argument_list COMMA expression
    {
        ArgList* list = $1;
        int new_count = list->argument_count + 1;
        ASTNode** new_args = malloc(sizeof(ASTNode*) * new_count);
        
        for (int i = 0; i < list->argument_count; i++) {
            new_args[i] = list->arguments[i];
        }
        
        new_args[list->argument_count] = $3;
        
        free(list->arguments);
        list->arguments = new_args;
        list->argument_count = new_count;
        $$ = list;
    }
    ;

// 数组字面量规则 - 支持空元素
array_literal
    : LBRACKET array_element_list_opt RBRACKET
    {
        $$ = create_array_literal($2->arguments, $2->argument_count);
        free($2);
    }
    ;

array_element_list_opt
    : /* empty */
    {
        $$ = malloc(sizeof(ArgList));
        $$->arguments = malloc(sizeof(ASTNode*) * 0);
        $$->argument_count = 0;
    }
    | array_element_list
    {
        $$ = $1;
    }
    ;

array_element_list
    : /* empty */
    {
        $$ = malloc(sizeof(ArgList));
        $$->arguments = malloc(sizeof(ASTNode*) * 0);  // 改为0个元素
        $$->argument_count = 0;
    }
    | expression
    {
        $$ = malloc(sizeof(ArgList));
        $$->arguments = malloc(sizeof(ASTNode*) * 1);
        $$->arguments[0] = $1;
        $$->argument_count = 1;
    }
    | spread_element
    {
        $$ = malloc(sizeof(ArgList));
        $$->arguments = malloc(sizeof(ASTNode*) * 1);
        $$->arguments[0] = $1;
        $$->argument_count = 1;
    }
    | array_element_list COMMA
    {
        // 暂时忽略尾部空元素
        $$ = $1;
    }
    | array_element_list COMMA expression
    {
        int old_count = $1->argument_count;
        ASTNode** new_args = malloc(sizeof(ASTNode*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_args[i] = $1->arguments[i];
        }
        new_args[old_count] = $3;
        
        free($1->arguments);
        $1->arguments = new_args;
        $1->argument_count = old_count + 1;
        $$ = $1;
    }
    | array_element_list COMMA spread_element
    {
        int old_count = $1->argument_count;
        ASTNode** new_args = malloc(sizeof(ASTNode*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_args[i] = $1->arguments[i];
        }
        new_args[old_count] = $3;
        
        free($1->arguments);
        $1->arguments = new_args;
        $1->argument_count = old_count + 1;
        $$ = $1;
    }
    ;

// 对象字面量规则 - 添加计算属性支持
object_literal
    : LBRACE property_list_opt RBRACE
    {
        $$ = create_object_literal($2->properties, $2->property_count);
        free($2);
    }
    ;

property_list_opt
    : /* empty */
    {
        $$ = malloc(sizeof(PropertyList));
        $$->properties = malloc(sizeof(ASTNode*) * 0);
        $$->property_count = 0;
    }
    | property_list
    {
        $$ = $1;
    }
    ;

property_list
    : property
    {
        $$ = malloc(sizeof(PropertyList));
        $$->properties = malloc(sizeof(ASTNode*) * 1);
        $$->properties[0] = $1;
        $$->property_count = 1;
    }
    | property_list COMMA property
    {
        int old_count = $1->property_count;
        ASTNode** new_props = malloc(sizeof(ASTNode*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_props[i] = $1->properties[i];
        }
        new_props[old_count] = $3;
        
        free($1->properties);
        $1->properties = new_props;
        $1->property_count = old_count + 1;
        $$ = $1;
    }
    ;

property
    : IDENTIFIER COLON expression
    {
        $$ = create_property(create_identifier($1), $3, 0, 0);
        free($1);
    }
    | IDENTIFIER
    {
        $$ = create_property(create_identifier($1), create_identifier($1), 1, 0);
        free($1);
    }
    | STRING COLON expression
    {
        $$ = create_property(create_string($1), $3, 0, 0);
        free($1);
    }
    | LBRACKET expression RBRACKET COLON expression
    {
        $$ = create_property($2, $5, 0, 1);
    }
    ;

// 统一箭头函数处理
arrow_function
    : LPAREN parameter_list_opt RPAREN ARROW expression
    {
        ASTNode* body = create_expression_statement($5);
        $$ = create_arrow_function($2, body);
        free($2);
    }
    | LPAREN parameter_list_opt RPAREN ARROW block_statement
    {
        $$ = create_arrow_function($2, $5);
        free($2);
    }
    | IDENTIFIER ARROW expression
    {
        ParamList* param_list = malloc(sizeof(ParamList));
        param_list->parameters = malloc(sizeof(char*) * 1);
        param_list->parameters[0] = strdup($1);
        param_list->parameter_count = 1;
        
        ASTNode* body = create_expression_statement($3);
        $$ = create_arrow_function(param_list, body);
        free($1);
        free(param_list->parameters);
        free(param_list);
    }
    | IDENTIFIER ARROW block_statement
    {
        ParamList* param_list = malloc(sizeof(ParamList));
        param_list->parameters = malloc(sizeof(char*) * 1);
        param_list->parameters[0] = strdup($1);
        param_list->parameter_count = 1;
        
        $$ = create_arrow_function(param_list, $3);
        free($1);
        free(param_list->parameters);
        free(param_list);
    }
    ;

// 展开运算符规则
spread_element
    : DOT_DOT_DOT expression
    {
        $$ = create_spread_element($2);
    }
    ;

%%

void yyerror(ScannerState *scanner, const char *s) {
    (void)scanner;
    fprintf(stderr, "PARSER: Syntax error: %s\n", s);
    if (global_scanner) {
        fprintf(stderr, "PARSER: At position: %d\n", global_scanner->pos);
        int start = global_scanner->pos - 10;
        if (start < 0) start = 0;
        size_t length = 30;
        size_t input_len = strlen(global_scanner->input);
        if (start + length > input_len) {
            length = input_len - start;
        }
        fprintf(stderr, "PARSER: Context: '%.*s'\n", (int)length, global_scanner->input + start);
        fprintf(stderr, "PARSER:           %*s^\n", global_scanner->pos - start, "");
    }
}