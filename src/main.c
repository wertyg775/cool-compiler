#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "token.h"

int main(int argc, char* argv[]){ //argc is the number of args, if argc = 1, only program name was given (./coolc)
    if (argc > 2) {
        fprintf(stderr, "error: no input file given");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r"); // argv is filename, "r" means read
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

    while(1) {
        Token token = lexer_next_token(&lexer);

        const char* token_type = token_type_name(token.type);

        printf("%s '%.*s'\n",
            token_type,
            token.length,
            token.start);

        if (token.type == TOKEN_EOF){
            return 0;
        }  
    }



    return 0;

    
}