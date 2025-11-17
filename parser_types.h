#ifndef PARSER_TYPES_H
#define PARSER_TYPES_H

#include "ast.h"

// 定义参数列表结构
typedef struct {
    ASTNode** arguments;
    int argument_count;
} ArgList;

typedef struct {
    char** parameters;
    int parameter_count;
} ParamList;

// 添加类相关的结构体
typedef struct {
    ASTNode** elements;
    int element_count;
} ClassElementList;

typedef struct {
    char* kind;
    char* key;
    ASTNode* value;
} MethodDefinition;

typedef struct {
    char* key;
    ASTNode* value;
} PropertyDefinition;

// 添加数组相关的结构体
typedef struct {
    ASTNode** elements;
    int element_count;
} ArrayElementList;

#endif