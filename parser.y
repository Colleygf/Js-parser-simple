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
    ArgList* arg_list;
    ParamList* param_list;
}

%token IF ELSE WHILE FOR FUNCTION VAR LET CONST RETURN BREAK CONTINUE
%token TRUE FALSE NULL_LITERAL UNDEFINED
%token NEWLINE
%token <str> IDENTIFIER NUMBER STRING
%token PLUS MINUS STAR SLASH PERCENT
%token EQUALS EQ_EQ NOT_EQ STRICT_EQ STRICT_NOT_EQ
%token LT LE GT GE BANG AND OR
%token PLUS_PLUS MINUS_MINUS PLUS_EQ MINUS_EQ STAR_EQ SLASH_EQ
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA DOT COLON QUESTION
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
%nonassoc CALL             /* 函数调用和成员访问 */
%left DOT LBRACKET

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
%type <node> call_expression member_expression
%type <node> expression_opt for_init for_cond for_iter
%type <param_list> parameter_list_opt parameter_list
%type <node> asi_semicolon
%type <arg_list> argument_list_opt argument_list

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
    | return_statement { $$ = $1; }
    | break_statement { $$ = $1; }
    | continue_statement { $$ = $1; }
    | block_statement { $$ = $1; }
    | empty_statement { $$ = $1; }
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
        free($2); // 释放临时的 program 节点，但保留其中的语句
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

/* 函数声明 */
function_declaration
    : FUNCTION IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement
    {
        $$ = create_function_declaration($2, $4->parameters, $4->parameter_count, $6);
        free($2);
        free($4); // 释放参数列表结构体，但不释放字符串（它们被转移到了 AST 节点中）
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
    | IDENTIFIER EQUALS assignment_expression
    {
        $$ = create_assignment_expression(OP_ASSIGN, create_identifier($1), $3);
        free($1);
    }
    | IDENTIFIER PLUS_EQ assignment_expression
    {
        $$ = create_assignment_expression(OP_ADD_ASSIGN, create_identifier($1), $3);
        free($1);
    }
    | IDENTIFIER MINUS_EQ assignment_expression
    {
        $$ = create_assignment_expression(OP_SUB_ASSIGN, create_identifier($1), $3);
        free($1);
    }
    | IDENTIFIER STAR_EQ assignment_expression
    {
        $$ = create_assignment_expression(OP_MUL_ASSIGN, create_identifier($1), $3);
        free($1);
    }
    | IDENTIFIER SLASH_EQ assignment_expression
    {
        $$ = create_assignment_expression(OP_DIV_ASSIGN, create_identifier($1), $3);
        free($1);
    }
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
        // 注意：这里需要为逻辑非创建一个新的操作符类型
        $$ = create_unary_expression(OP_SUB, $2); // 临时使用减法操作符
    }
    ;

postfix_expression
    : primary_expression { $$ = $1; }
    | call_expression { $$ = $1; }
    | member_expression { $$ = $1; }
    ;

/* 调用表达式 */
call_expression
    : primary_expression LPAREN argument_list_opt RPAREN
    {
        $$ = create_call_expression($1, $3->arguments, $3->argument_count);
        free($3);
    }
    | call_expression LPAREN argument_list_opt RPAREN
    {
        $$ = create_call_expression($1, $3->arguments, $3->argument_count);
        free($3);
    }
    | member_expression LPAREN argument_list_opt RPAREN
    {
        $$ = create_call_expression($1, $3->arguments, $3->argument_count);
        free($3);
    }
    ;
    
postfix_expression
    : primary_expression { $$ = $1; }
    | call_expression { $$ = $1; }
    | member_expression { $$ = $1; }
    | postfix_expression PLUS_PLUS %prec POST_INC
    {
        $$ = create_unary_expression(OP_POST_INC, $1);
    }
    | postfix_expression MINUS_MINUS %prec POST_DEC
    {
        $$ = create_unary_expression(OP_POST_DEC, $1);
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
    | PLUS_PLUS unary_expression  // 前缀递增
    {
        $$ = create_unary_expression(OP_PRE_INC, $2);
    }
    | MINUS_MINUS unary_expression  // 前缀递减
    {
        $$ = create_unary_expression(OP_PRE_DEC, $2);
    }
    ;
/* 成员表达式 */
member_expression
    : primary_expression DOT IDENTIFIER
    {
        $$ = create_member_expression($1, create_identifier($3), 0);
        free($3);
    }
    | member_expression DOT IDENTIFIER
    {
        $$ = create_member_expression($1, create_identifier($3), 0);
        free($3);
    }
    | primary_expression LBRACKET expression RBRACKET
    {
        $$ = create_member_expression($1, $3, 1);
    }
    | member_expression LBRACKET expression RBRACKET
    {
        $$ = create_member_expression($1, $3, 1);
    }
    ;

primary_expression
    : IDENTIFIER { $$ = create_identifier($1); free($1); }
    | NUMBER { $$ = create_number($1); free($1); }
    | STRING { $$ = create_string($1); free($1); }
    | TRUE { $$ = create_boolean(1); }
    | FALSE { $$ = create_boolean(0); }
    | NULL_LITERAL { $$ = create_null(); }
    | UNDEFINED { $$ = create_undefined(); }
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
        $$ = malloc(sizeof(ArgList));
        $$->arguments = malloc(sizeof(ASTNode*) * 1);
        $$->arguments[0] = $1;
        $$->argument_count = 1;
    }
    | argument_list COMMA expression
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

%%

void yyerror(ScannerState *scanner, const char *s) {
    (void)scanner; // 标记为未使用，消除警告
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