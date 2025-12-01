#include <stdio.h>
#include <string.h>
#include "common.h"
#include "parser_types.h"

/**
 * 检查是否应该插入分号
 * 基于 ECMAScript ASI 规则
 */
int should_insert_semicolon(ScannerState *scanner) {
    if (!scanner || !scanner->input) return 0;
    
    // 获取当前位置之后的字符
    const char* input = scanner->input + scanner->pos;
    
    // 如果遇到以下情况，不插入分号：
    // 1. 下一个token是括号、方括号、点操作符等
    // 2. 下一个token是二元操作符
    // 3. 其他不应该中断表达式的情况
    
    // 跳过空白
    while (*input && (*input == ' ' || *input == '\t' || *input == '\r')) {
        input++;
    }
    
    if (!*input) return 1; // 文件结束，应该插入分号
    
    // 检查下一个字符
    char next_char = *input;
    
    // 不应该插入分号的情况
    switch (next_char) {
        case '(': case '[': case '{':
        case '.': case ',': case ':': case '?':
        case '+': case '-': case '*': case '/': case '%':
        case '&': case '|': case '^': case '~':
        case '<': case '>': case '=': case '!':
            return 0; // 不插入分号
        default:
            break;
    }
    
    // 默认情况下插入分号
    return 1;
}

/**
 * 检查是否在语句末尾
 */
int at_statement_end(ScannerState *scanner) {
    if (!scanner || !scanner->input) return 1;
    
    // 获取当前位置之后的字符
    const char* input = scanner->input + scanner->pos;
    
    // 跳过空白
    while (*input && (*input == ' ' || *input == '\t' || *input == '\r')) {
        input++;
    }
    
    if (!*input) return 1; // 文件结束
    
    // 检查下一个字符是否是语句分隔符或块结束符
    char next_char = *input;
    
    // 语句结束的情况
    switch (next_char) {
        case '}': case ';': case ',': case ':':
            return 1;
        default:
            // 检查是否是关键字（新语句的开始）
            if (strncmp(input, "function", 8) == 0 ||
                strncmp(input, "if", 2) == 0 ||
                strncmp(input, "for", 3) == 0 ||
                strncmp(input, "while", 5) == 0 ||
                strncmp(input, "return", 6) == 0 ||
                strncmp(input, "break", 5) == 0 ||
                strncmp(input, "continue", 8) == 0 ||
                strncmp(input, "var", 3) == 0 ||
                strncmp(input, "let", 3) == 0 ||
                strncmp(input, "const", 5) == 0 ||
                strncmp(input, "class", 5) == 0) {
                return 1;
            }
            break;
    }
    
    return 0;
}