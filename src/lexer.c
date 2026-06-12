#include "lexer.h"
#include <ctype.h>
#include <string.h>

void lexer_init(Lexer *lexer, const char *source){
    lexer->source = source;
    lexer->current = source;
    lexer->line = 1;
    lexer->column = 1;
}

Token lexer_next_token(Lexer *lexer) {
    Token token;
    while (lexer->current[0] == ' ' || lexer->current[0] == '\n'){
        lexer->current += 1;
        lexer->column += 1;
    }

    token.start = lexer->current;
    token.line = lexer->line;
    token.column = lexer->column;

    if (lexer->current[0] == '\0') {
        token.type = TOKEN_EOF;
        token.length = 0;
        return token;
    }

    if (isalpha(lexer->current[0])){
        const char *start = lexer->current;

        while (isalnum(lexer->current[0]) ||
               lexer->current[0] == '_') {
            lexer->current += 1;
            lexer->column += 1;
               }    
        
        int length = lexer->current - start;

        if (length == 5 && strncmp(start, "class", 5) == 0) {
            token.type = TOKEN_CLASS;
            token.length = length;

            return token;
        }

        if (isupper(start[0])) {
            token.type = TOKEN_TYPE_IDENTIFIER;
            token.length = length;

            return token;
        }

        token.type = TOKEN_OBJECT_IDENTIFIER;
        token.length = length;

        return token;
    }
    
    if (lexer->current[0] == '{'){
        token.type = TOKEN_LBRACE;
        token.length = 1;

        lexer->current += 1;
        lexer->column += 1;

        return token;
    }

    if (lexer->current[0] == '}'){
        token.type = TOKEN_RBRACE;
        token.length = 1;

        lexer->current += 1;
        lexer->column += 1;

        return token;
    }
    
    token.type = TOKEN_ERROR;
    token.length = 1;
    lexer->current += 1;
    lexer->column += 1;
    return token;
}