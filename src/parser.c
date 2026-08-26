#include "parser.h"
#include <stdio.h>



void parser_init(Parser *p, Lexer *lexer){
    p->lexer = lexer;
    p->token = lexer_next_token(lexer);
}

// Consume the current token: pull the next one into p->token.
static void parser_advance(Parser *p){
    p->token = lexer_next_token(p->lexer);
}

// If the current token is `type`, consume it and return 1.
// Otherwise report an error at the token's location and return 0.
static int parser_expect(Parser *p, TokenType type){
    if (p->token.type != type){
        fprintf(stderr, "%d:%d: error: expected %s, got %s\n",
            p->token.line, p->token.column,
            token_type_name(type), token_type_name(p->token.type));
        return 0;
    }
    parser_advance(p);
    return 1;
}


// Parses exactly: class TYPE { } ;   Returns 1 on success, 0 on error.
int parse_class(Parser *p){
    if (!parser_expect(p, TOKEN_CLASS))           return 0;  // class
    if (!parser_expect(p, TOKEN_TYPE_IDENTIFIER)) return 0;  // Main
    if (p->token.type == TOKEN_INHERITS){
        parser_advance(p);
        if (!parser_expect(p, TOKEN_TYPE_IDENTIFIER)) return 0;
    }
    if (!parser_expect(p, TOKEN_LBRACE))          return 0;  // {
    if (!parser_expect(p, TOKEN_RBRACE))          return 0;  // }
    if (!parser_expect(p, TOKEN_SEMICOLON))       return 0;  // ;

    // EOF is terminal - check it but don't consume past it.
    if (p->token.type != TOKEN_EOF){
        fprintf(stderr, "%d:%d: error: expected end of file, got %s\n",
            p->token.line, p->token.column, token_type_name(p->token.type));
        return 0;
    }
    return 1;
}
