#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "ast.h"           // 添加 ast.h
#include "parser_types.h"  // 添加 parser_types.h

// 包含 bison 生成的头文件
#include "parser.h"

#define YYCTYPE unsigned char
#define YYCURSOR cursor
#define YYLIMIT limit
#define YYMARKER marker
#define YYFILL(n) {}

// 全局变量用于跟踪输入
ScannerState *global_scanner = NULL;

void set_scanner(ScannerState *scanner) {
    global_scanner = scanner;
}

// 调试函数：打印token信息
void print_token(const char* name, const char* value) {
    printf("LEXER: Token %s", name);
    if (value && strlen(value) > 0) {
        printf(" ('%s')", value);
    }
    printf(" at position %d\n", global_scanner->pos);
}

int yylex(void) {
    const unsigned char *cursor, *marker;
    const unsigned char *start;
    
    if (!global_scanner || !global_scanner->input) {
        printf("LEXER: No input\n");
        return 0;
    }
    
    cursor = (const unsigned char *)global_scanner->input + global_scanner->pos;
    
scan:
    start = cursor;
    
/*!re2c
re2c:yyfill:enable = 0;
re2c:define:YYCTYPE = "unsigned char";

/* 空白字符 - 包括换行符 */
[ \t\v\f\r\n]+ { 
    global_scanner->pos += cursor - start;
    printf("LEXER: Skipped whitespace/newline\n");
    goto scan; 
}

/* 注释 */
"//" [^\r\n]* { 
    global_scanner->pos += cursor - start;
    printf("LEXER: Skipped comment\n");
    goto scan; 
}
"/*" [^*]* "*"+ [^*/]* "*"+ "/" { 
    global_scanner->pos += cursor - start;
    printf("LEXER: Skipped block comment\n");
    goto scan; 
}

/* 关键字 */
"if" { 
    global_scanner->pos += cursor - start;
    print_token("IF", "");
    return IF; 
}
"else" { 
    global_scanner->pos += cursor - start;
    print_token("ELSE", "");
    return ELSE; 
}
"while" { 
    global_scanner->pos += cursor - start;
    print_token("WHILE", "");
    return WHILE; 
}
"for" { 
    global_scanner->pos += cursor - start;
    print_token("FOR", "");
    return FOR; 
}
"function" { 
    global_scanner->pos += cursor - start;
    print_token("FUNCTION", "");
    return FUNCTION; 
}
"var" { 
    global_scanner->pos += cursor - start;
    print_token("VAR", "");
    return VAR; 
}
"let" { 
    global_scanner->pos += cursor - start;
    print_token("LET", "");
    return LET; 
}
"const" { 
    global_scanner->pos += cursor - start;
    print_token("CONST", "");
    return CONST; 
}
"return" { 
    global_scanner->pos += cursor - start;
    print_token("RETURN", "");
    return RETURN; 
}
"break" { 
    global_scanner->pos += cursor - start;
    print_token("BREAK", "");
    return BREAK; 
}
"continue" { 
    global_scanner->pos += cursor - start;
    print_token("CONTINUE", "");
    return CONTINUE; 
}
"true" { 
    global_scanner->pos += cursor - start;
    print_token("TRUE", "");
    return TRUE; 
}
"false" { 
    global_scanner->pos += cursor - start;
    print_token("FALSE", "");
    return FALSE; 
}
"null" { 
    global_scanner->pos += cursor - start;
    print_token("NULL_LITERAL", "");
    return NULL_LITERAL; 
}
"undefined" { 
    global_scanner->pos += cursor - start;
    print_token("UNDEFINED", "");
    return UNDEFINED; 
}
"class" { 
    global_scanner->pos += cursor - start;
    print_token("CLASS", "");
    return CLASS; 
}
"new" { 
    global_scanner->pos += cursor - start;
    print_token("NEW", "");
    return NEW; 
}
"this" { 
    global_scanner->pos += cursor - start;
    print_token("THIS", "");
    return THIS; 
}
"super" { 
    global_scanner->pos += cursor - start;
    print_token("SUPER", "");
    return SUPER; 
}
"static" { 
    global_scanner->pos += cursor - start;
    print_token("STATIC", "");
    return STATIC; 
}
"extends" { 
    global_scanner->pos += cursor - start;
    print_token("EXTENDS", "");
    return EXTENDS; 
}
"constructor" { 
    global_scanner->pos += cursor - start;
    print_token("CONSTRUCTOR", "");
    return CONSTRUCTOR; 
}

/* 数字 */
[0-9]+ {
    global_scanner->pos += cursor - start;
    char *text = strndup((char*)start, cursor - start);
    if (!text) {
        fprintf(stderr, "LEXER: Failed to allocate memory for number\n");
        return 0;
    }
    print_token("NUMBER", text);
    yylval.str = text;  // 将所有权转移给解析器
    // 不要在这里 free(text)! 解析器会负责释放
    return NUMBER;
}

/* 字符串 */
["] ([^"\\] | "\\" [^])* ["] {
    global_scanner->pos += cursor - start;
    char *text = strndup((char*)start, cursor - start);
    if (!text) {
        fprintf(stderr, "LEXER: Failed to allocate memory for string\n");
        return 0;
    }
    print_token("STRING", text);
    yylval.str = text;  // 将所有权转移给解析器
    // 不要在这里 free(text)! 解析器会负责释放
    return STRING;
}

/* 标识符 */
[a-zA-Z_][a-zA-Z0-9_]* {
    global_scanner->pos += cursor - start;
    char *text = strndup((char*)start, cursor - start);
    if (!text) {
        fprintf(stderr, "LEXER: Failed to allocate memory for identifier\n");
        return 0;
    }
    print_token("IDENTIFIER", text);
    yylval.str = text;  // 将所有权转移给解析器
    // 不要在这里 free(text)! 解析器会负责释放
    return IDENTIFIER;
}
['] ([^'\\] | "\\" [^])* ['] {
    global_scanner->pos += cursor - start;
    char *text = strndup((char*)start, cursor - start);
    print_token("STRING", text);
    free(text);
    return STRING;
}

/* 运算符 */
"+" { global_scanner->pos += cursor - start; print_token("PLUS", ""); return PLUS; }
"-" { global_scanner->pos += cursor - start; print_token("MINUS", ""); return MINUS; }
"*" { global_scanner->pos += cursor - start; print_token("STAR", ""); return STAR; }
"/" { global_scanner->pos += cursor - start; print_token("SLASH", ""); return SLASH; }
"%" { global_scanner->pos += cursor - start; print_token("PERCENT", ""); return PERCENT; }
"=" { global_scanner->pos += cursor - start; print_token("EQUALS", ""); return EQUALS; }
"==" { global_scanner->pos += cursor - start; print_token("EQ_EQ", ""); return EQ_EQ; }
"!=" { global_scanner->pos += cursor - start; print_token("NOT_EQ", ""); return NOT_EQ; }
"<" { global_scanner->pos += cursor - start; print_token("LT", ""); return LT; }
"<=" { global_scanner->pos += cursor - start; print_token("LE", ""); return LE; }
">" { global_scanner->pos += cursor - start; print_token("GT", ""); return GT; }
">=" { global_scanner->pos += cursor - start; print_token("GE", ""); return GE; }
"!" { global_scanner->pos += cursor - start; print_token("BANG", ""); return BANG; }
"&&" { global_scanner->pos += cursor - start; print_token("AND", ""); return AND; }
"||" { global_scanner->pos += cursor - start; print_token("OR", ""); return OR; }

/* 扩展的运算符 */
"===" { global_scanner->pos += cursor - start; print_token("STRICT_EQ", ""); return STRICT_EQ; }
"!==" { global_scanner->pos += cursor - start; print_token("STRICT_NOT_EQ", ""); return STRICT_NOT_EQ; }
"++" { global_scanner->pos += cursor - start; print_token("PLUS_PLUS", ""); return PLUS_PLUS; }
"--" { global_scanner->pos += cursor - start; print_token("MINUS_MINUS", ""); return MINUS_MINUS; }
"+=" { global_scanner->pos += cursor - start; print_token("PLUS_EQ", ""); return PLUS_EQ; }
"-=" { global_scanner->pos += cursor - start; print_token("MINUS_EQ", ""); return MINUS_EQ; }
"*=" { global_scanner->pos += cursor - start; print_token("STAR_EQ", ""); return STAR_EQ; }
"/=" { global_scanner->pos += cursor - start; print_token("SLASH_EQ", ""); return SLASH_EQ; }

/* 扩展的分隔符 */
"[" { global_scanner->pos += cursor - start; print_token("LBRACKET", ""); return LBRACKET; }
"]" { global_scanner->pos += cursor - start; print_token("RBRACKET", ""); return RBRACKET; }
"." { global_scanner->pos += cursor - start; print_token("DOT", ""); return DOT; }
":" { global_scanner->pos += cursor - start; print_token("COLON", ""); return COLON; }
"?" { global_scanner->pos += cursor - start; print_token("QUESTION", ""); return QUESTION; }

/* 分隔符 */
"(" { global_scanner->pos += cursor - start; print_token("LPAREN", ""); return LPAREN; }
")" { global_scanner->pos += cursor - start; print_token("RPAREN", ""); return RPAREN; }
"{" { global_scanner->pos += cursor - start; print_token("LBRACE", ""); return LBRACE; }
"}" { global_scanner->pos += cursor - start; print_token("RBRACE", ""); return RBRACE; }
";" { global_scanner->pos += cursor - start; print_token("SEMICOLON", ""); return SEMICOLON; }
"," { global_scanner->pos += cursor - start; print_token("COMMA", ""); return COMMA; }

/* 文件结束 */
"\000" { 
    printf("LEXER: End of file\n");
    return 0; 
}

/* 错误字符 */
[^] { 
    fprintf(stderr, "LEXER: Invalid character: %c (0x%02x) at position %d\n", *start, *start, global_scanner->pos);
    global_scanner->pos += cursor - start;
    return 0;  // 返回0表示结束
}
*/
}