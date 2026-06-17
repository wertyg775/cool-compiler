#include <stdio.h>
#include "lexer.h"
#include "token.h"

int main(int argc, char* argv[]){ //argc is the number of args, if argc = 1, only program name was given (./coolc)
    if (argc < 2){
        fprintf(stderr, "error: no input file given\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL){
        fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
        return 1;
    }
    fseek(fp, 0, SEEK_END); // move pointer to end of byte
    long size = ftell(fp); // if fp has 5 bytes, fseek above sets pointer/cursor to end of file. ftell returns position of fseek which indirectly gets the size
    fseek(fp, 0, SEEK_SET); // resets fp beginning of file

    char *buffer = malloc(size +1);

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