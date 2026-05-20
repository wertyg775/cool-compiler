#include "lexer.h"

void lexer_init(Lexer *lexer, const char *source){
    lexer->source = source;
    lexer->current = source;
    lexer->line = 1;
    lexer->column = 1;
}

Token lexer_next_token(Lexer *lexer) {
    Token token;

    token.start = lexer->current;
    token.line = lexer->line;
    token.column = lexer->column;

    if (lexer->current[0] == '\0') {
        token.type = TOKEN_EOF;
        token.length = 0;
        return token;
    }

    if (lexer->current[0] == 'c' &&
        lexer->current[1] == 'l' &&
        lexer->current[2] == 'a' &&
        lexer->current[3] == 's' &&
        lexer->current[4] == 's') {
        
            token.type = TOKEN_CLASS;
            token.length = 5;

            lexer->current += 5;
            lexer->column += 5;

            return token;
        }
    
    token.type = TOKEN_ERROR;
    token.length = 1;
    lexer->current += 1;
    lexer->column += 1;
    return token;
}