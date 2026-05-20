#include <stdio.h>
#include "lexer.h"
#include "token.h"

int main(void){
    const char *source = "class Main {}";

    Lexer lexer;
    lexer_init(&lexer, source);

    Token token = lexer_next_token(&lexer);

    printf("%s\n", token_type_name(token.type));

    return 0;

    
}