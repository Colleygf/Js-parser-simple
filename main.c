#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

// 声明函数
int yyparse(void);
void set_scanner(ScannerState *scanner);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <javascript_file>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *input = malloc(file_size + 1);
    if (!input) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }
    
    size_t bytes_read = fread(input, 1, file_size, file);
    input[bytes_read] = '\0';
    fclose(file);
    
    ScannerState scanner;
    scanner.input = input;
    scanner.pos = 0;
    
    // 设置全局扫描器
    set_scanner(&scanner);
    
    printf("Parsing JavaScript file: %s\n", argv[1]);
    
    int result = yyparse();
    
    if (result == 0) {
        printf("✓ Syntax is valid\n");
    } else {
        printf("✗ Syntax errors found\n");
    }
    
    free(input);
    return result;
}