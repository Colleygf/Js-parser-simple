# Makefile for JavaScript Parser

CC = gcc
CFLEX = re2c
BISON = bison
CFLAGS = -Wall -Wextra -g

.PHONY: all clean test

all: js-parser

common.h:
	echo "#ifndef COMMON_H\n#define COMMON_H\n\ntypedef struct scanner_state {\n    const char *input;\n    int pos;\n} ScannerState;\n\n#endif" > common.h

ast.h:
	# 这里应该确保 ast.h 文件存在且有正确内容
	touch ast.h

parser_types.h:
	# 创建 parser_types.h
	echo "#ifndef PARSER_TYPES_H\n#define PARSER_TYPES_H\n\n#include \"ast.h\"\n\n// 定义参数列表结构\ntypedef struct {\n    ASTNode** arguments;\n    int argument_count;\n} ArgList;\n\ntypedef struct {\n    char** parameters;\n    int parameter_count;\n} ParamList;\n\n#endif" > parser_types.h

lexer.c: lexer.l common.h ast.h parser_types.h
	$(CFLEX) -o lexer.c lexer.l

parser.c parser.h: parser.y common.h ast.h parser_types.h
	$(BISON) -d -o parser.c parser.y

ast.c: ast.h
	# 这里应该确保 ast.c 文件存在且有正确内容
	touch ast.c

js-parser: main.c lexer.c parser.c ast.c common.h ast.h parser_types.h
	$(CC) $(CFLAGS) -o js-parser main.c lexer.c parser.c ast.c -lm

test: js-parser
	@echo "Testing JavaScript parser..."
	@mkdir -p test_files
	@echo "var x = 1; function test() { return x; }" > test_files/basic_syntax.js
	./js-parser test_files/basic_syntax.js

clean:
	rm -f js-parser lexer.c parser.c parser.h *.o parser_types.h

install-deps:
	sudo apt update
	sudo apt install re2c bison build-essential