#include "parser.h"
#include <stdio.h>



void parser_init(Parser *p, Lexer *lexer){
    p->lexer = lexer;
    p->token = lexer_next_token(lexer);
}


int parse_class(Parser *p){
    // expect: class
    if (p->token.type != TOKEN_CLASS){
        fprintf(stderr, "%d:%d: error: expected 'class', got %s\n",
            p->token.line, p->token.column, token_type_name(p->token.type));
        return 0;
    }
    p->token = lexer_next_token(p->lexer);

    // expect: class name (a type identifier, e.g. Main)
    if (p->token.type != TOKEN_TYPE_IDENTIFIER){
        fprintf(stderr, "%d:%d: error: expected class name, got %s\n",
            p->token.line, p->token.column, token_type_name(p->token.type));
        return 0;
    }
    p->token = lexer_next_token(p->lexer);

    // expect: {
    if (p->token.type != TOKEN_LBRACE){
        fprintf(stderr, "%d:%d: error: expected '{', got %s\n",
            p->token.line, p->token.column, token_type_name(p->token.type));
        return 0;
    }
    p->token = lexer_next_token(p->lexer);

    // expect: }
    if (p->token.type != TOKEN_RBRACE){
        fprintf(stderr, "%d:%d: error: expected '}', got %s\n",
            p->token.line, p->token.column, token_type_name(p->token.type));
        return 0;
    }
    p->token = lexer_next_token(p->lexer);

    // expect: ;
    if (p->token.type != TOKEN_SEMICOLON){
        fprintf(stderr, "%d:%d: error: expected ';', got %s\n",
            p->token.line, p->token.column, token_type_name(p->token.type));
        return 0;
    }
    p->token = lexer_next_token(p->lexer);

    // expect: end of file (nothing should follow this single class)
    if (p->token.type != TOKEN_EOF){
        fprintf(stderr, "%d:%d: error: expected end of file, got %s\n",
            p->token.line, p->token.column, token_type_name(p->token.type));
        return 0;
    }

    return 1;
}
