# Makefile for JavaScript Parser

CC = gcc
CFLEX = re2c
BISON = bison
CFLAGS = -Wall -Wextra -g

.PHONY: all clean test

all: js-parser

common.h:
	echo "#ifndef COMMON_H\n#define COMMON_H\n\ntypedef struct scanner_state {\n    const char *input;\n    int pos;\n} ScannerState;\n\n#endif" > common.h

lexer.c: lexer.l common.h
	$(CFLEX) -o lexer.c lexer.l

parser.c parser.h: parser.y common.h
	$(BISON) -d -o parser.c parser.y

js-parser: main.c lexer.c parser.c common.h
	$(CC) $(CFLAGS) -o js-parser main.c lexer.c parser.c -lm

test: js-parser
	@echo "Testing JavaScript parser..."
	./js-parser simple.js

clean:
	rm -f js-parser lexer.c parser.c parser.h common.h *.o

install-deps:
	sudo apt update
	sudo apt install re2c bison build-essential