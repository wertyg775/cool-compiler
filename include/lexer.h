#ifndef COOL_LEXER_H
#define COOL_LEXER_H

#include "token.h"

typedef struct {
    const char *source; //pointer to beginning of whole string
    const char *current; //pointer to character the lexer is currently looking at
    int line;
    int column;
} Lexer;

void lexer_init(Lexer *lexer, const char *source);
Token lexer_next_token(Lexer *lexer);

#endif