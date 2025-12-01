#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// 创建标识符节点
ASTNode* create_identifier(const char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_IDENTIFIER;
    node->line = 0; // 在实际解析器中应该设置行号
    node->column = 0; // 和列号
    node->data.identifier.name = strdup(name);
    return node;
}

// 创建数字字面量节点
ASTNode* create_number(const char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_NUMBER;
    node->line = 0;
    node->column = 0;
    node->data.literal.value = strdup(value);
    return node;
}

// 创建字符串字面量节点
ASTNode* create_string(const char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_STRING;
    node->line = 0;
    node->column = 0;
    node->data.literal.value = strdup(value);
    return node;
}

// 创建布尔字面量节点
ASTNode* create_boolean(int value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_BOOLEAN;
    node->line = 0;
    node->column = 0;
    node->data.literal.value = strdup(value ? "true" : "false");
    return node;
}

// 创建 null 字面量节点
ASTNode* create_null(void) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_NULL;
    node->line = 0;
    node->column = 0;
    node->data.literal.value = strdup("null");
    return node;
}

// 创建 undefined 字面量节点
ASTNode* create_undefined(void) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_UNDEFINED;
    node->line = 0;
    node->column = 0;
    node->data.literal.value = strdup("undefined");
    return node;
}

// 创建二元表达式节点
ASTNode* create_binary_expression(OperatorType op, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_BINARY_OP;
    node->line = 0;
    node->column = 0;
    node->data.binary_expr.op = op;
    node->data.binary_expr.left = left;
    node->data.binary_expr.right = right;
    return node;
}

// 创建一元表达式节点
ASTNode* create_unary_expression(OperatorType op, ASTNode* operand) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_UNARY_OP;
    node->line = 0;
    node->column = 0;
    node->data.unary_expr.op = op;
    node->data.unary_expr.operand = operand;
    return node;
}

// 创建赋值表达式节点
ASTNode* create_assignment_expression(OperatorType op, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_ASSIGNMENT;
    node->line = 0;
    node->column = 0;
    node->data.assignment.op = op;
    node->data.assignment.left = left;
    node->data.assignment.right = right;
    return node;
}

// 创建调用表达式节点
ASTNode* create_call_expression(ASTNode* callee, ASTNode** arguments, int argument_count) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_CALL_EXPRESSION;
    node->line = 0;
    node->column = 0;
    node->data.call_expr.callee = callee;
    node->data.call_expr.arguments = arguments;
    node->data.call_expr.argument_count = argument_count;
    return node;
}

// 创建成员表达式节点
ASTNode* create_member_expression(ASTNode* object, ASTNode* property, int computed) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_MEMBER_EXPRESSION;
    node->line = 0;
    node->column = 0;
    node->data.member_expr.object = object;
    node->data.member_expr.property = property;
    node->data.member_expr.computed = computed;
    return node;
}

// 创建条件表达式节点
ASTNode* create_conditional_expression(ASTNode* test, ASTNode* consequent, ASTNode* alternate) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_CONDITIONAL_EXPRESSION;
    node->line = 0;
    node->column = 0;
    node->data.conditional_expr.test = test;
    node->data.conditional_expr.consequent = consequent;
    node->data.conditional_expr.alternate = alternate;
    return node;
}

// 创建程序节点
ASTNode* create_program(ASTNode** statements, int statement_count) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_PROGRAM;
    node->line = 0;
    node->column = 0;
    node->data.program.statements = statements;
    node->data.program.statement_count = statement_count;
    return node;
}

// 创建变量声明节点
ASTNode* create_variable_declaration(const char* kind, const char* name, ASTNode* init) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_VARIABLE_DECLARATION;
    node->line = 0;
    node->column = 0;
    node->data.variable_decl.kind = strdup(kind);
    node->data.variable_decl.name = strdup(name);
    node->data.variable_decl.init = init;
    return node;
}

// 创建函数声明节点
ASTNode* create_function_declaration(const char* name, char** parameters, int parameter_count, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_FUNCTION_DECLARATION;
    node->line = 0;
    node->column = 0;
    node->data.function_decl.name = strdup(name);
    node->data.function_decl.parameters = parameters;
    node->data.function_decl.parameter_count = parameter_count;
    node->data.function_decl.body = body;
    return node;
}

// 创建表达式语句节点
ASTNode* create_expression_statement(ASTNode* expression) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_EXPRESSION_STATEMENT;
    node->line = 0;
    node->column = 0;
    node->data.expression_stmt.expression = expression;
    return node;
}

// 创建块语句节点
ASTNode* create_block_statement(ASTNode** body, int body_count) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_BLOCK_STATEMENT;
    node->line = 0;
    node->column = 0;
    node->data.block_stmt.body = body;
    node->data.block_stmt.body_count = body_count;
    return node;
}

// 创建 if 语句节点
ASTNode* create_if_statement(ASTNode* test, ASTNode* consequent, ASTNode* alternate) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_IF_STATEMENT;
    node->line = 0;
    node->column = 0;
    node->data.if_stmt.test = test;
    node->data.if_stmt.consequent = consequent;
    node->data.if_stmt.alternate = alternate;
    return node;
}

// 创建 while 语句节点
ASTNode* create_while_statement(ASTNode* test, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_WHILE_STATEMENT;
    node->line = 0;
    node->column = 0;
    node->data.while_stmt.test = test;
    node->data.while_stmt.body = body;
    return node;
}

// 创建 for 语句节点
ASTNode* create_for_statement(ASTNode* init, ASTNode* test, ASTNode* update, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_FOR_STATEMENT;
    node->line = 0;
    node->column = 0;
    node->data.for_stmt.init = init;
    node->data.for_stmt.test = test;
    node->data.for_stmt.update = update;
    node->data.for_stmt.body = body;
    return node;
}

// 创建 return 语句节点
ASTNode* create_return_statement(ASTNode* argument) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_RETURN_STATEMENT;
    node->line = 0;
    node->column = 0;
    node->data.return_stmt.argument = argument;
    return node;
}

// 创建 break 语句节点
ASTNode* create_break_statement(void) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_BREAK_STATEMENT;
    node->line = 0;
    node->column = 0;
    return node;
}

// 创建 continue 语句节点
ASTNode* create_continue_statement(void) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_CONTINUE_STATEMENT;
    node->line = 0;
    node->column = 0;
    return node;
}

// 创建空语句节点
ASTNode* create_empty_statement(void) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_EMPTY_STATEMENT;
    node->line = 0;
    node->column = 0;
    return node;
}

// 创建类声明节点
ASTNode* create_class_declaration(const char* name, ASTNode* super_class, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_CLASS_DECLARATION;
    node->line = 0;
    node->column = 0;
    node->data.class_decl.name = strdup(name);
    node->data.class_decl.super_class = super_class;
    node->data.class_decl.body = body;
    return node;
}

// 创建 new 表达式节点
ASTNode* create_new_expression(ASTNode* callee, ASTNode** arguments, int argument_count) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_NEW_EXPRESSION;
    node->line = 0;
    node->column = 0;
    node->data.new_expr.callee = callee;
    node->data.new_expr.arguments = arguments;
    node->data.new_expr.argument_count = argument_count;
    return node;
}

// 创建 this 表达式节点
ASTNode* create_this_expression(void) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_THIS_EXPRESSION;
    node->line = 0;
    node->column = 0;
    return node;
}

// 创建 super 表达式节点
ASTNode* create_super_expression(void) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_SUPER_EXPRESSION;
    node->line = 0;
    node->column = 0;
    return node;
}

// 创建类体节点
ASTNode* create_class_body(ASTNode** elements, int element_count) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_CLASS_BODY;
    node->line = 0;
    node->column = 0;
    node->data.class_body.elements = elements;
    node->data.class_body.element_count = element_count;
    return node;
}

// 创建类方法节点
ASTNode* create_class_method(const char* kind, const char* key, ASTNode* value, int is_static) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_CLASS_METHOD;
    node->line = 0;
    node->column = 0;
    node->data.class_method.kind = strdup(kind);
    node->data.class_method.key = strdup(key);
    node->data.class_method.value = value;
    node->data.class_method.is_static = is_static;
    return node;
}

// 创建类属性节点
ASTNode* create_class_property(const char* key, ASTNode* value, int is_static) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_CLASS_PROPERTY;
    node->line = 0;
    node->column = 0;
    node->data.class_property.key = strdup(key);
    node->data.class_property.value = value;
    node->data.class_property.is_static = is_static;
    return node;
}

// 创建数组字面量节点
ASTNode* create_array_literal(ASTNode** elements, int element_count) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_ARRAY_LITERAL;
    node->line = 0;
    node->column = 0;
    node->data.array_literal.elements = elements;
    node->data.array_literal.element_count = element_count;
    return node;
}

// 创建数组访问节点
ASTNode* create_array_access(ASTNode* array, ASTNode* index) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_ARRAY_ACCESS;
    node->line = 0;
    node->column = 0;
    node->data.array_access.array = array;
    node->data.array_access.index = index;
    return node;
}


// 创建对象字面量节点
ASTNode* create_object_literal(ASTNode** properties, int property_count) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_OBJECT_LITERAL;
    node->line = 0;
    node->column = 0;
    node->data.object_literal.properties = properties;
    node->data.object_literal.property_count = property_count;
    return node;
}

// 创建对象属性节点
ASTNode* create_property(ASTNode* key, ASTNode* value, int shorthand, int computed) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_PROPERTY;
    node->line = 0;
    node->column = 0;
    node->data.property.key = key;
    node->data.property.value = value;
    node->data.property.shorthand = shorthand;
    node->data.property.computed = computed;
    return node;
}

// 创建箭头函数节点
ASTNode* create_arrow_function(ParamList* params, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_ARROW_FUNCTION;
    node->line = 0;
    node->column = 0;
    node->data.arrow_function.params = params;
    node->data.arrow_function.body = body;
    return node;
}

// 创建展开元素节点
ASTNode* create_spread_element(ASTNode* argument) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_SPREAD_ELEMENT;
    node->line = 0;
    node->column = 0;
    node->data.spread_element.argument = argument;
    return node;
}

// 创建模板字符串节点
ASTNode* create_template_literal(ASTNode** parts, int part_count) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_TEMPLATE_LITERAL;
    node->line = 0;
    node->column = 0;
    node->data.template_literal.parts = parts;
    node->data.template_literal.part_count = part_count;
    return node;
}

// 创建正则表达式字面量节点
ASTNode* create_regexp_literal(const char* pattern, const char* flags) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_REGEXP_LITERAL;
    node->line = 0;
    node->column = 0;
    node->data.regexp_literal.pattern = strdup(pattern);
    node->data.regexp_literal.flags = flags ? strdup(flags) : NULL;
    return node;
}

// 创建函数表达式节点
ASTNode* create_function_expression(const char* name, char** parameters, int parameter_count, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_FUNCTION_EXPRESSION;
    node->line = 0;
    node->column = 0;
    node->data.function_decl.name = name ? strdup(name) : NULL;
    node->data.function_decl.parameters = parameters;
    node->data.function_decl.parameter_count = parameter_count;
    node->data.function_decl.body = body;
    return node;
}

// 创建 switch 语句节点（简化版本）
ASTNode* create_switch_statement(ASTNode* discriminant, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_SWITCH_STATEMENT;
    node->line = 0;
    node->column = 0;
    node->data.switch_stmt.discriminant = discriminant;
    node->data.switch_stmt.body = body;
    return node;
}

// 创建 try 语句节点（简化版本）
ASTNode* create_try_statement(ASTNode* block, ASTNode* handler, ASTNode* finalizer) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_TRY_STATEMENT;
    node->line = 0;
    node->column = 0;
    node->data.try_stmt.block = block;
    node->data.try_stmt.handler = handler;
    node->data.try_stmt.finalizer = finalizer;
    return node;
}


// 释放 AST 节点
void free_ast(ASTNode* node) {
    if (!node) return;
    
    switch (node->type) {
        case AST_IDENTIFIER:
            free(node->data.identifier.name);
            break;
            
        case AST_NUMBER:
        case AST_STRING:
        case AST_BOOLEAN:
        case AST_NULL:
        case AST_UNDEFINED:
            if (node->data.literal.value) {
                free(node->data.literal.value);
            }
            break;
            
        case AST_BINARY_OP:
            free_ast(node->data.binary_expr.left);
            free_ast(node->data.binary_expr.right);
            break;
            
        case AST_UNARY_OP:
            free_ast(node->data.unary_expr.operand);
            break;
            
        case AST_ASSIGNMENT:
            free_ast(node->data.assignment.left);
            free_ast(node->data.assignment.right);
            break;
            
        case AST_CALL_EXPRESSION:
            free_ast(node->data.call_expr.callee);
            for (int i = 0; i < node->data.call_expr.argument_count; i++) {
                free_ast(node->data.call_expr.arguments[i]);
            }
            free(node->data.call_expr.arguments);
            break;
            
        case AST_MEMBER_EXPRESSION:
            free_ast(node->data.member_expr.object);
            free_ast(node->data.member_expr.property);
            break;
            
        case AST_CONDITIONAL_EXPRESSION:
            free_ast(node->data.conditional_expr.test);
            free_ast(node->data.conditional_expr.consequent);
            free_ast(node->data.conditional_expr.alternate);
            break;
            
        case AST_PROGRAM:
            for (int i = 0; i < node->data.program.statement_count; i++) {
                free_ast(node->data.program.statements[i]);
            }
            free(node->data.program.statements);
            break;
            
        case AST_VARIABLE_DECLARATION:
            free(node->data.variable_decl.kind);
            free(node->data.variable_decl.name);
            free_ast(node->data.variable_decl.init);
            break;
            
        case AST_FUNCTION_DECLARATION:
            free(node->data.function_decl.name);
            for (int i = 0; i < node->data.function_decl.parameter_count; i++) {
                free(node->data.function_decl.parameters[i]);
            }
            free(node->data.function_decl.parameters);
            free_ast(node->data.function_decl.body);
            break;
            
        case AST_EXPRESSION_STATEMENT:
            free_ast(node->data.expression_stmt.expression);
            break;
            
        case AST_BLOCK_STATEMENT:
            for (int i = 0; i < node->data.block_stmt.body_count; i++) {
                free_ast(node->data.block_stmt.body[i]);
            }
            free(node->data.block_stmt.body);
            break;
            
        case AST_IF_STATEMENT:
            free_ast(node->data.if_stmt.test);
            free_ast(node->data.if_stmt.consequent);
            if (node->data.if_stmt.alternate) {
                free_ast(node->data.if_stmt.alternate);
            }
            break;
            
        case AST_WHILE_STATEMENT:
            free_ast(node->data.while_stmt.test);
            free_ast(node->data.while_stmt.body);
            break;
            
        case AST_FOR_STATEMENT:
            if (node->data.for_stmt.init) free_ast(node->data.for_stmt.init);
            if (node->data.for_stmt.test) free_ast(node->data.for_stmt.test);
            if (node->data.for_stmt.update) free_ast(node->data.for_stmt.update);
            free_ast(node->data.for_stmt.body);
            break;
            
        case AST_RETURN_STATEMENT:
            if (node->data.return_stmt.argument) {
                free_ast(node->data.return_stmt.argument);
            }
            break;
        
                
        case AST_CLASS_DECLARATION:
            free(node->data.class_decl.name);
            if (node->data.class_decl.super_class) {
                free_ast(node->data.class_decl.super_class);
            }
            free_ast(node->data.class_decl.body);
            break;
            
        case AST_NEW_EXPRESSION:
            free_ast(node->data.new_expr.callee);
            for (int i = 0; i < node->data.new_expr.argument_count; i++) {
                free_ast(node->data.new_expr.arguments[i]);
            }
            free(node->data.new_expr.arguments);
            break;
            
        case AST_THIS_EXPRESSION:
        case AST_SUPER_EXPRESSION:
            // 这些节点没有额外数据需要释放
            break;
            
        case AST_CLASS_BODY:
            for (int i = 0; i < node->data.class_body.element_count; i++) {
                free_ast(node->data.class_body.elements[i]);
            }
            free(node->data.class_body.elements);
            break;
            
        case AST_CLASS_METHOD:
            free(node->data.class_method.kind);
            free(node->data.class_method.key);
            free_ast(node->data.class_method.value);
            break;
            
        case AST_CLASS_PROPERTY:
            free(node->data.class_property.key);
            if (node->data.class_property.value) {
                free_ast(node->data.class_property.value);
            }
            break;

        case AST_ARRAY_LITERAL:
            for (int i = 0; i < node->data.array_literal.element_count; i++) {
                free_ast(node->data.array_literal.elements[i]);
            }
            free(node->data.array_literal.elements);
            break;
            
        case AST_ARRAY_ACCESS:
            free_ast(node->data.array_access.array);
            free_ast(node->data.array_access.index);
            break;
       
        case AST_OBJECT_LITERAL:
            for (int i = 0; i < node->data.object_literal.property_count; i++) {
                free_ast(node->data.object_literal.properties[i]);
            }
            free(node->data.object_literal.properties);
            break;
            
        case AST_PROPERTY:
            free_ast(node->data.property.key);
            free_ast(node->data.property.value);
            break;
            
        case AST_ARROW_FUNCTION:
            // 释放参数列表
            if (node->data.arrow_function.params) {
                ParamList* params = node->data.arrow_function.params;
                for (int i = 0; i < params->parameter_count; i++) {
                    free(params->parameters[i]);
                }
                free(params->parameters);
                free(params);
            }
            free_ast(node->data.arrow_function.body);
            break;
            
        case AST_SPREAD_ELEMENT:
            free_ast(node->data.spread_element.argument);
            break;
        case AST_TEMPLATE_LITERAL:
            for (int i = 0; i < node->data.template_literal.part_count; i++) {
                 free_ast(node->data.template_literal.parts[i]);
            }
            free(node->data.template_literal.parts);
            break;
    
        case AST_REGEXP_LITERAL:
            free(node->data.regexp_literal.pattern);
            if (node->data.regexp_literal.flags) {
                free(node->data.regexp_literal.flags);
            }
            break;
        case AST_FUNCTION_EXPRESSION:
            if (node->data.function_decl.name) {
                free(node->data.function_decl.name);
                   }
            for (int i = 0; i < node->data.function_decl.parameter_count; i++) {
                 free(node->data.function_decl.parameters[i]);
                   }
            free(node->data.function_decl.parameters);
            free_ast(node->data.function_decl.body);
            break;
        
        case AST_SWITCH_STATEMENT:
            free_ast(node->data.switch_stmt.discriminant);
            free_ast(node->data.switch_stmt.body);
            break;
            
        case AST_TRY_STATEMENT:
            free_ast(node->data.try_stmt.block);
            if (node->data.try_stmt.handler) {
                free_ast(node->data.try_stmt.handler);
            }
            if (node->data.try_stmt.finalizer) {
                free_ast(node->data.try_stmt.finalizer);
            }
            break;

        case AST_BREAK_STATEMENT:
        case AST_CONTINUE_STATEMENT:
        case AST_EMPTY_STATEMENT:
            // 这些节点没有额外数据需要释放
            break;
        
        default:
            break;
    }
    
    free(node);
}

// 打印 AST 节点（用于调试）
void print_ast(ASTNode* node, int indent) {
    if (!node) return;
    
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    
    switch (node->type) {
        case AST_IDENTIFIER:
            printf("Identifier: %s\n", node->data.identifier.name);
            break;
            
        case AST_NUMBER:
            printf("Number: %s\n", node->data.literal.value);
            break;
            
        case AST_STRING:
            printf("String: \"%s\"\n", node->data.literal.value);
            break;
            
        case AST_BOOLEAN:
            printf("Boolean: %s\n", node->data.literal.value);
            break;
            
        case AST_NULL:
            printf("Null\n");
            break;
            
        case AST_UNDEFINED:
            printf("Undefined\n");
            break;
           
        case AST_BINARY_OP: {
            const char* op_str;
            switch (node->data.binary_expr.op) {
                case OP_ADD: op_str = "+"; break;
                case OP_SUB: op_str = "-"; break;
                case OP_MUL: op_str = "*"; break;
                case OP_DIV: op_str = "/"; break;
                case OP_MOD: op_str = "%"; break;
                case OP_EQ: op_str = "=="; break;
                case OP_NEQ: op_str = "!="; break;
                case OP_STRICT_EQ: op_str = "==="; break;
                case OP_STRICT_NEQ: op_str = "!=="; break;
                case OP_LT: op_str = "<"; break;
                case OP_LE: op_str = "<="; break;
                case OP_GT: op_str = ">"; break;
                case OP_GE: op_str = ">="; break;
                case OP_AND: op_str = "&&"; break;
                case OP_OR: op_str = "||"; break;
                default: op_str = "?"; break;
            }
            printf("BinaryOp: %s\n", op_str);
            print_ast(node->data.binary_expr.left, indent + 1);
            print_ast(node->data.binary_expr.right, indent + 1);
            break;
        }
            
        case AST_ASSIGNMENT: {
            const char* op_str;
            switch (node->data.assignment.op) {
                case OP_ASSIGN: op_str = "="; break;
                case OP_ADD_ASSIGN: op_str = "+="; break;
                case OP_SUB_ASSIGN: op_str = "-="; break;
                case OP_MUL_ASSIGN: op_str = "*="; break;
                case OP_DIV_ASSIGN: op_str = "/="; break;
                default: op_str = "?"; break;
            }
            printf("Assignment: %s\n", op_str);
            print_ast(node->data.assignment.left, indent + 1);
            print_ast(node->data.assignment.right, indent + 1);
            break;
        }
            
        case AST_CALL_EXPRESSION:
            printf("CallExpression\n");
            print_ast(node->data.call_expr.callee, indent + 1);
            for (int i = 0; i < node->data.call_expr.argument_count; i++) {
                print_ast(node->data.call_expr.arguments[i], indent + 1);
            }
            break;
            
        case AST_MEMBER_EXPRESSION:
            printf("MemberExpression (%s)\n", node->data.member_expr.computed ? "computed" : "dot");
            print_ast(node->data.member_expr.object, indent + 1);
            print_ast(node->data.member_expr.property, indent + 1);
            break;
            
        case AST_CONDITIONAL_EXPRESSION:
            printf("ConditionalExpression\n");
            print_ast(node->data.conditional_expr.test, indent + 1);
            print_ast(node->data.conditional_expr.consequent, indent + 1);
            print_ast(node->data.conditional_expr.alternate, indent + 1);
            break;
            
        case AST_PROGRAM:
            printf("Program\n");
            for (int i = 0; i < node->data.program.statement_count; i++) {
                print_ast(node->data.program.statements[i], indent + 1);
            }
            break;
            
        case AST_VARIABLE_DECLARATION:
            printf("VariableDeclaration: %s %s\n", node->data.variable_decl.kind, node->data.variable_decl.name);
            if (node->data.variable_decl.init) {
                print_ast(node->data.variable_decl.init, indent + 1);
            }
            break;
            
        case AST_FUNCTION_DECLARATION:
            printf("FunctionDeclaration: %s\n", node->data.function_decl.name);
            for (int i = 0; i < node->data.function_decl.parameter_count; i++) {
                for (int j = 0; j < indent + 1; j++) printf("  ");
                printf("Parameter: %s\n", node->data.function_decl.parameters[i]);
            }
            print_ast(node->data.function_decl.body, indent + 1);
            break;
            
        case AST_EXPRESSION_STATEMENT:
            printf("ExpressionStatement\n");
            if (node->data.expression_stmt.expression) {
                print_ast(node->data.expression_stmt.expression, indent + 1);
            }
            break;
            
        case AST_BLOCK_STATEMENT:
            printf("BlockStatement\n");
            for (int i = 0; i < node->data.block_stmt.body_count; i++) {
                print_ast(node->data.block_stmt.body[i], indent + 1);
            }
            break;
            
        case AST_IF_STATEMENT:
            printf("IfStatement\n");
            print_ast(node->data.if_stmt.test, indent + 1);
            print_ast(node->data.if_stmt.consequent, indent + 1);
            if (node->data.if_stmt.alternate) {
                print_ast(node->data.if_stmt.alternate, indent + 1);
            }
            break;
            
        case AST_WHILE_STATEMENT:
            printf("WhileStatement\n");
            print_ast(node->data.while_stmt.test, indent + 1);
            print_ast(node->data.while_stmt.body, indent + 1);
            break;
            
        case AST_FOR_STATEMENT:
            printf("ForStatement\n");
            if (node->data.for_stmt.init) print_ast(node->data.for_stmt.init, indent + 1);
            if (node->data.for_stmt.test) print_ast(node->data.for_stmt.test, indent + 1);
            if (node->data.for_stmt.update) print_ast(node->data.for_stmt.update, indent + 1);
            print_ast(node->data.for_stmt.body, indent + 1);
            break;
            
        case AST_RETURN_STATEMENT:
            printf("ReturnStatement\n");
            if (node->data.return_stmt.argument) {
                print_ast(node->data.return_stmt.argument, indent + 1);
            }
            break;
            
        case AST_BREAK_STATEMENT:
            printf("BreakStatement\n");
            break;
            
        case AST_CONTINUE_STATEMENT:
            printf("ContinueStatement\n");
            break;
            
        case AST_EMPTY_STATEMENT:
            printf("EmptyStatement\n");
            break;

        case AST_UNARY_OP: {
            const char* op_str;
            switch (node->data.unary_expr.op) {
                case OP_ADD: op_str = "+"; break;
                case OP_SUB: op_str = "-"; break;
                case OP_MUL: op_str = "*"; break;
                case OP_DIV: op_str = "/"; break;
                case OP_MOD: op_str = "%"; break;
                case OP_EQ: op_str = "=="; break;
                case OP_NEQ: op_str = "!="; break;
                case OP_STRICT_EQ: op_str = "==="; break;
                case OP_STRICT_NEQ: op_str = "!=="; break;
                case OP_LT: op_str = "<"; break;
                case OP_LE: op_str = "<="; break;
                case OP_GT: op_str = ">"; break;
                case OP_GE: op_str = ">="; break;
                case OP_AND: op_str = "&&"; break;
                case OP_OR: op_str = "||"; break;
                case OP_ASSIGN: op_str = "="; break;
                case OP_ADD_ASSIGN: op_str = "+="; break;
                case OP_SUB_ASSIGN: op_str = "-="; break;
                case OP_MUL_ASSIGN: op_str = "*="; break;
                case OP_DIV_ASSIGN: op_str = "/="; break;
                case OP_PRE_INC: op_str = "++(prefix)"; break;
                case OP_PRE_DEC: op_str = "--(prefix)"; break;
                case OP_POST_INC: op_str = "(postfix)++"; break;
                case OP_POST_DEC: op_str = "(postfix)--"; break;
                case OP_NOT: op_str = "!"; break;
                default: op_str = "?"; break;
            }
            printf("UnaryOp: %s\n", op_str);
            print_ast(node->data.unary_expr.operand, indent + 1);
            break;
        }

        case AST_CLASS_DECLARATION:
            printf("ClassDeclaration: %s\n", node->data.class_decl.name);
            if (node->data.class_decl.super_class) {
                for (int i = 0; i < indent + 1; i++) printf("  ");
                printf("SuperClass:\n");
                print_ast(node->data.class_decl.super_class, indent + 2);
            }
            print_ast(node->data.class_decl.body, indent + 1);
            break;
            
        case AST_NEW_EXPRESSION:
            printf("NewExpression\n");
            print_ast(node->data.new_expr.callee, indent + 1);
            for (int i = 0; i < node->data.new_expr.argument_count; i++) {
                print_ast(node->data.new_expr.arguments[i], indent + 1);
            }
            break;
            
        case AST_THIS_EXPRESSION:
            printf("ThisExpression\n");
            break;
            
        case AST_SUPER_EXPRESSION:
            printf("SuperExpression\n");
            break;
            
        case AST_CLASS_BODY:
            printf("ClassBody\n");
            for (int i = 0; i < node->data.class_body.element_count; i++) {
                print_ast(node->data.class_body.elements[i], indent + 1);
            }
            break;
            
        case AST_CLASS_METHOD:
            printf("ClassMethod: %s %s%s\n", 
                   node->data.class_method.kind,
                   node->data.class_method.key,
                   node->data.class_method.is_static ? " (static)" : "");
            print_ast(node->data.class_method.value, indent + 1);
            break;
            
        case AST_CLASS_PROPERTY:
            printf("ClassProperty: %s%s\n", 
                   node->data.class_property.key,
                   node->data.class_property.is_static ? " (static)" : "");
            if (node->data.class_property.value) {
                print_ast(node->data.class_property.value, indent + 1);
            }
            break;
        
        case AST_ARRAY_LITERAL:
            printf("ArrayLiteral\n");
            for (int i = 0; i < node->data.array_literal.element_count; i++) {
                print_ast(node->data.array_literal.elements[i], indent + 1);
            }
            break;
            
        case AST_ARRAY_ACCESS:
            printf("ArrayAccess\n");
            print_ast(node->data.array_access.array, indent + 1);
            print_ast(node->data.array_access.index, indent + 1);
            break;
        
        
        case AST_OBJECT_LITERAL:
            printf("ObjectLiteral\n");
            for (int i = 0; i < node->data.object_literal.property_count; i++) {
                print_ast(node->data.object_literal.properties[i], indent + 1);
            }
            break;
            
        case AST_PROPERTY:
            printf("Property (shorthand: %s, computed: %s)\n", 
                   node->data.property.shorthand ? "yes" : "no",
                   node->data.property.computed ? "yes" : "no");
            print_ast(node->data.property.key, indent + 1);
            print_ast(node->data.property.value, indent + 1);
            break;
            
        case AST_ARROW_FUNCTION:
            printf("ArrowFunction\n");
            // 打印参数
            if (node->data.arrow_function.params) {
                ParamList* params = node->data.arrow_function.params;
                for (int i = 0; i < indent + 1; i++) printf("  ");
                printf("Parameters:\n");
                for (int i = 0; i < params->parameter_count; i++) {
                    for (int j = 0; j < indent + 2; j++) printf("  ");
                    printf("%s\n", params->parameters[i]);
                }
            }
            print_ast(node->data.arrow_function.body, indent + 1);
            break;
            
        case AST_SPREAD_ELEMENT:
            printf("SpreadElement\n");
            print_ast(node->data.spread_element.argument, indent + 1);
            break;
        case AST_SWITCH_STATEMENT:
            printf("SwitchStatement\n");
            print_ast(node->data.switch_stmt.discriminant, indent + 1);
            print_ast(node->data.switch_stmt.body, indent + 1);
            break;
            
        case AST_TRY_STATEMENT:
            printf("TryStatement\n");
            print_ast(node->data.try_stmt.block, indent + 1);
            if (node->data.try_stmt.handler) {
                for (int i = 0; i < indent + 1; i++) printf("  ");
                printf("CatchClause\n");
                print_ast(node->data.try_stmt.handler, indent + 2);
            }
            if (node->data.try_stmt.finalizer) {
                for (int i = 0; i < indent + 1; i++) printf("  ");
                printf("FinallyClause\n");
                print_ast(node->data.try_stmt.finalizer, indent + 2);
            }
            break;
        default:
            printf("Unknown AST node type: %d\n", node->type);
            break;
    }

}

