#ifndef AST_H
#define AST_H

typedef enum {
    // 表达式节点
    AST_IDENTIFIER,
    AST_NUMBER,
    AST_STRING,
    AST_BOOLEAN,
    AST_NULL,
    AST_UNDEFINED,
    AST_BINARY_OP,
    AST_UNARY_OP,
    AST_ASSIGNMENT,
    AST_CALL_EXPRESSION,
    AST_MEMBER_EXPRESSION,
    AST_CONDITIONAL_EXPRESSION,
    
    // 语句节点
    AST_PROGRAM,
    AST_VARIABLE_DECLARATION,
    AST_FUNCTION_DECLARATION,
    AST_EXPRESSION_STATEMENT,
    AST_BLOCK_STATEMENT,
    AST_IF_STATEMENT,
    AST_WHILE_STATEMENT,
    AST_FOR_STATEMENT,
    AST_RETURN_STATEMENT,
    AST_BREAK_STATEMENT,
    AST_CONTINUE_STATEMENT,
    AST_EMPTY_STATEMENT
} ASTNodeType;

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_EQ,
    OP_NEQ,
    OP_STRICT_EQ,
    OP_STRICT_NEQ,
    OP_LT,
    OP_LE,
    OP_GT,
    OP_GE,
    OP_AND,
    OP_OR,
    OP_ASSIGN,
    OP_ADD_ASSIGN,
    OP_SUB_ASSIGN,
    OP_MUL_ASSIGN,
    OP_DIV_ASSIGN,
    OP_PRE_INC,    // 前缀递增 ++x
    OP_PRE_DEC,    // 前缀递减 --x
    OP_POST_INC,   // 后缀递增 x++
    OP_POST_DEC,   // 后缀递减 x--
    OP_NOT         // 逻辑非 !x
} OperatorType;

// AST 节点结构
typedef struct ASTNode {
    ASTNodeType type;
    int line;
    int column;
    
    union {
        // 字面量
        struct {
            char* value;
        } literal;
        
        // 标识符
        struct {
            char* name;
        } identifier;
        
        // 二元运算
        struct {
            OperatorType op;
            struct ASTNode* left;
            struct ASTNode* right;
        } binary_expr;
        
        // 一元运算
        struct {
            OperatorType op;
            struct ASTNode* operand;
        } unary_expr;
        
        // 赋值表达式
        struct {
            OperatorType op;
            struct ASTNode* left;
            struct ASTNode* right;
        } assignment;
        
        // 调用表达式
        struct {
            struct ASTNode* callee;
            struct ASTNode** arguments;
            int argument_count;
        } call_expr;
        
        // 成员表达式
        struct {
            struct ASTNode* object;
            struct ASTNode* property;
            int computed; // 0 for dot, 1 for bracket
        } member_expr;
        
        // 条件表达式
        struct {
            struct ASTNode* test;
            struct ASTNode* consequent;
            struct ASTNode* alternate;
        } conditional_expr;
        
        // 程序
        struct {
            struct ASTNode** statements;
            int statement_count;
        } program;
        
        // 变量声明
        struct {
            char* kind; // "var", "let", "const"
            char* name;
            struct ASTNode* init;
        } variable_decl;
        
        // 函数声明
        struct {
            char* name;
            char** parameters;
            int parameter_count;
            struct ASTNode* body;
        } function_decl;
        
        // 表达式语句
        struct {
            struct ASTNode* expression;
        } expression_stmt;
        
        // 块语句
        struct {
            struct ASTNode** body;
            int body_count;
        } block_stmt;
        
        // if 语句
        struct {
            struct ASTNode* test;
            struct ASTNode* consequent;
            struct ASTNode* alternate;
        } if_stmt;
        
        // while 语句
        struct {
            struct ASTNode* test;
            struct ASTNode* body;
        } while_stmt;
        
        // for 语句
        struct {
            struct ASTNode* init;
            struct ASTNode* test;
            struct ASTNode* update;
            struct ASTNode* body;
        } for_stmt;
        
        // return 语句
        struct {
            struct ASTNode* argument;
        } return_stmt;
    } data;
} ASTNode;

// AST 创建函数声明
ASTNode* create_identifier(const char* name);
ASTNode* create_number(const char* value);
ASTNode* create_string(const char* value);
ASTNode* create_boolean(int value);
ASTNode* create_null(void);
ASTNode* create_undefined(void);
ASTNode* create_binary_expression(OperatorType op, ASTNode* left, ASTNode* right);
ASTNode* create_unary_expression(OperatorType op, ASTNode* operand);
ASTNode* create_assignment_expression(OperatorType op, ASTNode* left, ASTNode* right);
ASTNode* create_call_expression(ASTNode* callee, ASTNode** arguments, int argument_count);
ASTNode* create_member_expression(ASTNode* object, ASTNode* property, int computed);
ASTNode* create_conditional_expression(ASTNode* test, ASTNode* consequent, ASTNode* alternate);
ASTNode* create_program(ASTNode** statements, int statement_count);
ASTNode* create_variable_declaration(const char* kind, const char* name, ASTNode* init);
ASTNode* create_function_declaration(const char* name, char** parameters, int parameter_count, ASTNode* body);
ASTNode* create_expression_statement(ASTNode* expression);
ASTNode* create_block_statement(ASTNode** body, int body_count);
ASTNode* create_if_statement(ASTNode* test, ASTNode* consequent, ASTNode* alternate);
ASTNode* create_while_statement(ASTNode* test, ASTNode* body);
ASTNode* create_for_statement(ASTNode* init, ASTNode* test, ASTNode* update, ASTNode* body);
ASTNode* create_return_statement(ASTNode* argument);
ASTNode* create_break_statement(void);
ASTNode* create_continue_statement(void);
ASTNode* create_empty_statement(void);

// 工具函数
void free_ast(ASTNode* node);
void print_ast(ASTNode* node, int indent);

#endif