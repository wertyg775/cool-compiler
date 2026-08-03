#ifndef COOL_PARSER_H
#define COOL_PARSER_H

#include "token.h"
#include "lexer.h"

typedef struct {
    Lexer *lexer;
    Token token;
} Parser;


void parser_init(Parser *p, Lexer *lexer);
int parse_class(Parser *p);


#endif
