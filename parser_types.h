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

#endif
