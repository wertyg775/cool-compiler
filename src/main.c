#include <stdio.h>
#include "lexer.h"
#include "token.h"

int main(void){
    const char *source = "class Main { \n Token }";

    Lexer lexer;
    lexer_init(&lexer, source);

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