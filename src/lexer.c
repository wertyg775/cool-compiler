#include "lexer.h"
#include <ctype.h>
#include <string.h>

static const TokenType char_token_map[128] = {
    ['{'] = TOKEN_LBRACE,
    ['}'] = TOKEN_RBRACE,
    ['['] = TOKEN_LBRACKET,
    [']'] = TOKEN_RBRACKET,
    [','] = TOKEN_COMMA,
    [':'] = TOKEN_COLON,
    ['.'] = TOKEN_DOT,
    ['@'] = TOKEN_AT,
    ['~'] = TOKEN_TILDE,
    [';'] = TOKEN_SEMICOLON,

    ['+'] = TOKEN_PLUS,
    ['-'] = TOKEN_MINUS,
    ['*'] = TOKEN_STAR,
    ['/'] = TOKEN_SLASH,
};

static const struct {
    const char *word;
    int         length;
    TokenType   type;
} keywords[] = {
    { "class",    5, TOKEN_CLASS    },
    { "else",     4, TOKEN_ELSE     },
    { "fi",       2, TOKEN_FI       },
    { "if",       2, TOKEN_IF       },
    { "in",       2, TOKEN_IN       },
    { "inherits", 8, TOKEN_INHERITS },
    { "isvoid",   6, TOKEN_ISVOID   },
    { "let",      3, TOKEN_LET      },
    { "loop",     4, TOKEN_LOOP     },
    { "pool",     4, TOKEN_POOL     },
    { "then",     4, TOKEN_THEN     },
    { "while",    5, TOKEN_WHILE    },
    { "case",     4, TOKEN_CASE     },
    { "esac",     4, TOKEN_ESAC     },
    { "new",      3, TOKEN_NEW      },
    { "of",       2, TOKEN_OF       },
    { "not",      3, TOKEN_NOT      },
    { "true",     4, TOKEN_BOOL_CONST },
    { "false",    5, TOKEN_BOOL_CONST },
};

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

    // IDENTIFIER LOOP
    if (isalpha(lexer->current[0])){
        const char *start = lexer->current;

        while (isalnum(lexer->current[0]) ||
               lexer->current[0] == '_') {
            lexer->current += 1;
            lexer->column += 1;
               }    
        
        int length = lexer->current - start;

        for (int i = 0; i < ARRAY_LEN(keywords); i++){
            
            if (length == keywords[i].length && strncmp(start, keywords[i].word, keywords[i].length) == 0){
                token.type = keywords[i].type;
                token.length = length;

                return token;
            }
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

    // INTEGER CONST LOOP
    if (isdigit(lexer->current[0])) {
        const char *start = lexer->current;
        while(isdigit(lexer->current[0])){
            lexer->current += 1;
            lexer->column += 1;
        }
        int length = lexer->current - start;

        token.type = INT_CONST;
        token.length = length;

        return token;
    }
    
    // SINGLE CHAR 
    if (char_token_map[(unsigned char) lexer->current[0]]) {
        token.type = char_token_map[(unsigned char) lexer->current[0]];
        token.length = 1;

        lexer->current += 1;
        lexer->column += 1;

        return token;
    }

    // STRING LITERAL
    if (lexer->current[0] == '"') {
        const char *start = lexer->current;
        lexer->current += 1;
        lexer->column += 1;
        int unterminated = 0;
        while(lexer->current[0] != '"'){
            if(lexer->current[0] == '\0'){
                unterminated = 1;
                break;
            }
            lexer->current += 1;
            lexer->column += 1;
        }
        if (unterminated){
            token.type = TOKEN_ERROR;
            token.length = lexer->current - start;

            return token;
        }
        else{
            lexer->current += 1;
            lexer->column += 1;

            token.type = STR_CONST;
            token.length = lexer->current - start;

            return token;
        }
    }

    // LESS , EQUAL , GREATER OPERATORS
    if (lexer->current[0] == '<'){
        if(lexer->current[1] == '='){
            token.type = TOKEN_LE;
            token.length = 2;
        }
        else if(lexer->current[1] == '-'){
            token.type = TOKEN_ASSIGN;
            token.length = 2;
        }
        else {
            token.type = TOKEN_LT;
            token.length = 1;
        }
        lexer->current += token.length;
        lexer->column += token.length;
        
        return token;
    }

    if (lexer->current[0] == '='){
        if (lexer->current[1] == '>'){
            token.type = TOKEN_DARROW;
            token.length = 2;
        }
        else {
            token.type = TOKEN_EQUAL;
            token.length = 1;
        }
        lexer->current += token.length;
        lexer->column += token.length;

        return token;
    }

    if (lexer->current[0] == '>'){
        if(lexer->current[1] == '='){
            token.type = TOKEN_GE;
            token.length = 2;
        }
        else{
            token.type = TOKEN_GT;
            token.length = 1;
        }
        lexer->current += token.length;
        lexer->column += token.length;
    }
    
    token.type = TOKEN_ERROR;
    token.length = 1;
    lexer->current += 1;
    lexer->column += 1;
    return token;
}