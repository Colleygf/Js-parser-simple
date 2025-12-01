#ifndef PARSER_TYPES_H
#define PARSER_TYPES_H

#include "ast.h"

// 定义参数列表结构 - 现在在 ast.h 中定义
// typedef struct {
//     char** parameters;
//     int parameter_count;
// } ParamList;

// 其他结构体定义保持不变
typedef struct {
    ASTNode** arguments;
    int argument_count;
} ArgList;

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

// 添加属性列表结构体
typedef struct {
    ASTNode** properties;
    int property_count;
} PropertyList;

#endif