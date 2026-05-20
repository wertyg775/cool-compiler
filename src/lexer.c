#include "lexer.h"

void lexer_init(Lexer *lexer, const char *source){
    lexer->source = source;
    lexer->current = source;
    lexer->line = 1;
    lexer->column = 1;
}

Token lexer_next_token(Lexer *lexer) {
    Token token;

    token.type = TOKEN_EOF;
    token.start = lexer->current;
    token.length = 0;
    token.line = lexer->line;
    token.column = lexer->column;

    return token;
}