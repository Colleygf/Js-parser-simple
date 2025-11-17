# Makefile for JavaScript Parser

CC = gcc
CFLEX = re2c
BISON = bison
CFLAGS = -Wall -Wextra -g

.PHONY: all clean test

all: js-parser


lexer.c: lexer.l common.h ast.h parser_types.h
	$(CFLEX) -o lexer.c lexer.l

parser.c parser.h: parser.y common.h ast.h parser_types.h
	$(BISON) -d -o parser.c parser.y


js-parser: main.c lexer.c parser.c ast.c common.h ast.h parser_types.h
	$(CC) $(CFLAGS) -o js-parser main.c lexer.c parser.c ast.c -lm

test: js-parser
	@echo "Testing JavaScript parser..."
	@mkdir -p test_files
	@echo "var x = 1; function test() { return x; }" > test_files/basic_syntax.js
	./js-parser test_files/basic_syntax.js

clean:
	rm -f js-parser lexer.c parser.c parser.h *.o 

install-deps:
	sudo apt update
	sudo apt install re2c bison build-essential