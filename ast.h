#ifndef AST_H
#define AST_H

/* 由于要求不构建AST，这里只定义基本结构用于参考 */

typedef enum {
    NODE_PROGRAM,
    NODE_FUNCTION,
    NODE_VARIABLE_DECL,
    NODE_EXPRESSION,
    NODE_IF,
    NODE_WHILE,
    NODE_FOR,
    NODE_RETURN,
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_IDENTIFIER,
    NODE_LITERAL
} NodeType;

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_ASSIGN,
    OP_EQ,
    OP_NEQ,
    OP_LT,
    OP_GT
} OperatorType;

struct ast_node {
    NodeType type;
    int line;
    int column;
    union {
        struct {
            struct ast_node **statements;
            int count;
        } program;
        
        struct {
            char *name;
            struct ast_node *body;
        } function;
        
        struct {
            char *name;
            struct ast_node *value;
        } variable;
        
        struct {
            OperatorType op;
            struct ast_node *left;
            struct ast_node *right;
        } binary_expr;
        
        struct {
            char *value;
        } literal;
        
        struct {
            char *name;
        } identifier;
    } data;
};

#endif