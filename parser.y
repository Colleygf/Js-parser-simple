%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

// 声明函数
int yylex(void);
void yyerror(const char *s);

// 声明全局变量
extern ScannerState *global_scanner;

%}

%token IF ELSE WHILE FOR FUNCTION VAR LET CONST RETURN BREAK CONTINUE
%token TRUE FALSE NULL_LITERAL UNDEFINED
%token NEWLINE
%token IDENTIFIER NUMBER STRING
%token PLUS MINUS STAR SLASH PERCENT
%token EQUALS EQ_EQ NOT_EQ STRICT_EQ STRICT_NOT_EQ
%token LT LE GT GE BANG AND OR
%token PLUS_PLUS MINUS_MINUS PLUS_EQ MINUS_EQ STAR_EQ SLASH_EQ
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA DOT COLON QUESTION
%token ERROR

/* 优先级和结合性 */
%left OR
%left AND
%left EQ_EQ NOT_EQ STRICT_EQ STRICT_NOT_EQ
%left LT LE GT GE
%left PLUS MINUS
%left STAR SLASH PERCENT
%right BANG
%right EQUALS PLUS_EQ MINUS_EQ STAR_EQ SLASH_EQ
%nonassoc QUESTION COLON
%left POSTFIX  /* 后缀运算符的优先级 */

%start program

%%

program
    : statements
    {
        printf("PARSER: Successfully parsed program\n");
    }
    ;

statements
    : /* empty */
    | statements statement
    ;

statement
    : variable_declaration
    | expression_statement
    | if_statement
    | while_statement
    | for_statement
    | function_declaration
    | return_statement
    | break_statement
    | continue_statement
    | block_statement
    | empty_statement
    {
        printf("PARSER: Parsed statement\n");
    }
    ;

/* 变量声明 - 支持ASI */
variable_declaration
    : VAR IDENTIFIER optional_initializer asi_semicolon
    | LET IDENTIFIER optional_initializer asi_semicolon
    | CONST IDENTIFIER optional_initializer asi_semicolon
    {
        printf("PARSER: Parsed variable declaration\n");
    }
    ;

optional_initializer
    : /* empty */
    | EQUALS expression
    ;

/* 表达式语句 - 支持ASI */
expression_statement
    : expression asi_semicolon
    {
        printf("PARSER: Parsed expression statement\n");
    }
    ;

/* ASI分号处理 - 简化和修复 */
asi_semicolon
    : SEMICOLON
    | NEWLINE
    {
        printf("PARSER: ASI - Automatically inserted semicolon after statement\n");
    }
    | /* empty */
    {
        printf("PARSER: ASI - Automatically inserted semicolon after statement\n");
    }
    ;

/* 空语句 */
empty_statement
    : SEMICOLON
    {
        printf("PARSER: Parsed empty statement\n");
    }
    ;

/* 块语句 */
block_statement
    : LBRACE statements RBRACE
    {
        printf("PARSER: Parsed block statement\n");
    }
    | LBRACE RBRACE
    {
        printf("PARSER: Parsed empty block statement\n");
    }
    ;

/* if 语句 */
if_statement
    : IF LPAREN expression RPAREN statement
    {
        printf("PARSER: Parsed if statement\n");
    }
    | IF LPAREN expression RPAREN statement ELSE statement
    {
        printf("PARSER: Parsed if-else statement\n");
    }
    ;

/* while 语句 */
while_statement
    : WHILE LPAREN expression RPAREN statement
    {
        printf("PARSER: Parsed while statement\n");
    }
    ;

/* for 语句 */
for_statement
    : FOR LPAREN for_init SEMICOLON for_cond SEMICOLON for_iter RPAREN statement
    {
        printf("PARSER: Parsed for statement\n");
    }
    ;

for_init
    : /* empty */
    | variable_declaration_no_semi
    | expression
    ;

for_cond
    : /* empty */
    | expression
    ;

for_iter
    : /* empty */
    | expression
    ;

variable_declaration_no_semi
    : VAR IDENTIFIER optional_initializer
    | LET IDENTIFIER optional_initializer
    | CONST IDENTIFIER optional_initializer
    ;

/* 函数声明 */
function_declaration
    : FUNCTION IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement
    {
        printf("PARSER: Parsed function declaration\n");
    }
    ;

parameter_list_opt
    : /* empty */
    | parameter_list
    ;

parameter_list
    : IDENTIFIER
    | parameter_list COMMA IDENTIFIER
    ;

/* 返回语句 - 支持ASI */
return_statement
    : RETURN expression_opt asi_semicolon
    {
        printf("PARSER: Parsed return statement\n");
    }
    ;

/* break 和 continue 语句 - 支持ASI */
break_statement
    : BREAK asi_semicolon
    {
        printf("PARSER: Parsed break statement\n");
    }
    ;

continue_statement
    : CONTINUE asi_semicolon
    {
        printf("PARSER: Parsed continue statement\n");
    }
    ;

expression_opt
    : /* empty */
    | expression
    ;

/* 表达式层次结构 */
expression
    : assignment_expression
    ;

assignment_expression
    : conditional_expression
    | IDENTIFIER EQUALS assignment_expression
    | IDENTIFIER PLUS_EQ assignment_expression
    | IDENTIFIER MINUS_EQ assignment_expression
    | IDENTIFIER STAR_EQ assignment_expression
    | IDENTIFIER SLASH_EQ assignment_expression
    ;

conditional_expression
    : logical_or_expression
    | logical_or_expression QUESTION expression COLON conditional_expression
    ;

logical_or_expression
    : logical_and_expression
    | logical_or_expression OR logical_and_expression
    ;

logical_and_expression
    : equality_expression
    | logical_and_expression AND equality_expression
    ;

equality_expression
    : relational_expression
    | equality_expression EQ_EQ relational_expression
    | equality_expression NOT_EQ relational_expression
    | equality_expression STRICT_EQ relational_expression
    | equality_expression STRICT_NOT_EQ relational_expression
    ;

relational_expression
    : additive_expression
    | relational_expression LT additive_expression
    | relational_expression LE additive_expression
    | relational_expression GT additive_expression
    | relational_expression GE additive_expression
    ;

additive_expression
    : multiplicative_expression
    | additive_expression PLUS multiplicative_expression
    | additive_expression MINUS multiplicative_expression
    ;

multiplicative_expression
    : unary_expression
    | multiplicative_expression STAR unary_expression
    | multiplicative_expression SLASH unary_expression
    | multiplicative_expression PERCENT unary_expression
    ;

unary_expression
    : postfix_expression
    | PLUS unary_expression
    | MINUS unary_expression
    | BANG unary_expression
    | PLUS_PLUS unary_expression
    | MINUS_MINUS unary_expression
    ;

/* 修复：添加后缀自增/自减运算符 */
postfix_expression
    : primary_expression
    | postfix_expression PLUS_PLUS %prec POSTFIX
    | postfix_expression MINUS_MINUS %prec POSTFIX
    | call_expression
    | member_expression
    ;

/* 简化的调用表达式 */
call_expression
    : primary_expression LPAREN argument_list_opt RPAREN
    | call_expression LPAREN argument_list_opt RPAREN
    | member_expression LPAREN argument_list_opt RPAREN
    ;

/* 简化的成员表达式 */
member_expression
    : primary_expression DOT IDENTIFIER
    | member_expression DOT IDENTIFIER
    ;

primary_expression
    : IDENTIFIER
    | NUMBER
    | STRING
    | TRUE
    | FALSE
    | NULL_LITERAL
    | UNDEFINED
    | LPAREN expression RPAREN
    ;

argument_list_opt
    : /* empty */
    | argument_list
    ;

argument_list
    : expression
    | argument_list COMMA expression
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "PARSER: Syntax error: %s\n", s);
    if (global_scanner) {
        fprintf(stderr, "PARSER: At position: %d\n", global_scanner->pos);
        // 打印当前位置附近的文本
        int start = global_scanner->pos - 10;
        if (start < 0) start = 0;
        int length = 30;
        if (start + length > strlen(global_scanner->input)) {
            length = strlen(global_scanner->input) - start;
        }
        fprintf(stderr, "PARSER: Context: '%.*s'\n", length, global_scanner->input + start);
        fprintf(stderr, "PARSER:           %*s^\n", global_scanner->pos - start, "");
    }
}