#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "token.h"

int main(int argc, char* argv[]){ //argc is the number of args, if argc = 1, only program name was given (./coolc)
    if (argc < 2) {
        fprintf(stderr, "error: no input file given");
        return 1;
    }
    char *input_file = NULL; // argv[1] returns a pointer
    int print_tokens = 0;
    for (int i = 1; i < argc; i++){
        if(strcmp(argv[i], "--tokens") == 0){
            print_tokens = 1;
        }
        else{
            input_file = argv[i];
        }
    }

    FILE *fp = fopen(input_file, "r"); // argv is filename, "r" means read
    if (fp == NULL){
        fprintf(stderr, "error: can't open file '%s'\n", argv[1]);
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = malloc(size + 1);

    fread(buffer, 1, size, fp);
    buffer[size] = '\0';

    fclose(fp);

    Lexer lexer;
    lexer_init(&lexer, buffer);
    
    if (print_tokens == 1){
        while(1) {
            Token token = lexer_next_token(&lexer);

            const char* token_type = token_type_name(token.type);

            printf("%s '%.*s'\n",
                token_type,
                token.length,
                token.start);

            if (token.type == TOKEN_EOF){
                break;
            }  
        }
    }

    free(buffer); //free the memory from heap



    return 0;

    
}