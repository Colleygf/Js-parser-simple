#ifndef AST_H
#define AST_H

// 首先定义参数列表结构，这样其他结构体可以使用
typedef struct {
    char** parameters;
    int parameter_count;
} ParamList;

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
    AST_FUNCTION_EXPRESSION,
    
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
    AST_EMPTY_STATEMENT,
    
    // 类和对象相关节点
    AST_CLASS_DECLARATION,
    AST_NEW_EXPRESSION,
    AST_THIS_EXPRESSION,
    AST_SUPER_EXPRESSION,
    AST_CLASS_BODY,
    AST_CLASS_METHOD,
    AST_CLASS_PROPERTY,
    
    // 数组相关节点
    AST_ARRAY_LITERAL,
    AST_ARRAY_ACCESS,
    
    // 新增现代语法特性节点
    AST_OBJECT_LITERAL,
    AST_PROPERTY,
    AST_ARROW_FUNCTION,
    AST_SPREAD_ELEMENT,
    AST_TEMPLATE_LITERAL,
    AST_REGEXP_LITERAL,

    // 新增：switch 和 try 语句（放在最后避免冲突）
    AST_SWITCH_STATEMENT,
    AST_TRY_STATEMENT

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
        
        // 类声明
        struct {
            char* name;
            struct ASTNode* super_class;  // 父类（可选）
            struct ASTNode* body;         // 类体
        } class_decl;
        
        // new 表达式
        struct {
            struct ASTNode* callee;
            struct ASTNode** arguments;
            int argument_count;
        } new_expr;
        
        // 类体
        struct {
            struct ASTNode** elements;
            int element_count;
        } class_body;
        
        // 类方法
        struct {
            char* kind;  // "method", "get", "set", "constructor"
            char* key;   // 方法名
            struct ASTNode* value; // 函数表达式
            int is_static;
        } class_method;
        
        // 类属性
        struct {
            char* key;   // 属性名
            struct ASTNode* value; // 初始值（可选）
            int is_static;
        } class_property;
        
        // 数组字面量
        struct {
            struct ASTNode** elements;
            int element_count;
        } array_literal;
        
        // 数组访问
        struct {
            struct ASTNode* array;
            struct ASTNode* index;
        } array_access;
        
        // 对象字面量
        struct {
            struct ASTNode** properties;
            int property_count;
        } object_literal;
        
        // 对象属性
        struct {
            struct ASTNode* key;
            struct ASTNode* value;
            int shorthand;
            int computed;
        } property;
        
        // 箭头函数
        struct {
            ParamList* params;  // 使用 ParamList 而不是 ASTNode*
            struct ASTNode* body;
        } arrow_function;
        
        // 展开元素
        struct {
            struct ASTNode* argument;
        } spread_element;
        
        // 模板字符串
        struct {
            struct ASTNode** parts;
            int part_count;
        } template_literal;
        
        //正则表达式字面量
        struct {
            char* pattern;
            char* flags;
        } regexp_literal;

        // 函数声明和函数表达式共用相同的数据结构
        struct {
            char* name;
            char** parameters;
            int parameter_count;
            struct ASTNode* body;
        } FunctionData;
        // 新增：简单的 switch 语句结构
        struct {
            struct ASTNode* discriminant;
            struct ASTNode* body;  // 使用块语句作为 body
        } switch_stmt;
        
        // 新增：简单的 try 语句结构
        struct {
            struct ASTNode* block;
            struct ASTNode* handler;  // catch 块
            struct ASTNode* finalizer; // finally 块
        } try_stmt;

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
// 函数表达式创建函数
ASTNode* create_function_expression(const char* name, char** parameters, int parameter_count, ASTNode* body);

// 类和对象相关函数
ASTNode* create_class_declaration(const char* name, ASTNode* super_class, ASTNode* body);
ASTNode* create_new_expression(ASTNode* callee, ASTNode** arguments, int argument_count);
ASTNode* create_this_expression(void);
ASTNode* create_super_expression(void);
ASTNode* create_class_body(ASTNode** elements, int element_count);
ASTNode* create_class_method(const char* kind, const char* key, ASTNode* value, int is_static);
ASTNode* create_class_property(const char* key, ASTNode* value, int is_static);

// 数组相关函数
ASTNode* create_array_literal(ASTNode** elements, int element_count);
ASTNode* create_array_access(ASTNode* array, ASTNode* index);

// 新增现代语法特性函数
ASTNode* create_object_literal(ASTNode** properties, int property_count);
ASTNode* create_property(ASTNode* key, ASTNode* value, int shorthand, int computed);
ASTNode* create_arrow_function(ParamList* params, ASTNode* body);  // 修改为 ParamList*
ASTNode* create_spread_element(ASTNode* argument);
ASTNode* create_template_literal(ASTNode** parts, int part_count);
ASTNode* create_regexp_literal(const char* pattern, const char* flags);


// 添加简单的创建函数声明
ASTNode* create_switch_statement(ASTNode* discriminant, ASTNode* body);
ASTNode* create_try_statement(ASTNode* block, ASTNode* handler, ASTNode* finalizer);

// 工具函数
void free_ast(ASTNode* node);
void print_ast(ASTNode* node, int indent);

#endif