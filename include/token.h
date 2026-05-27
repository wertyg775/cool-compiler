#ifndef COOL_TOKEN_H
#define COOL_TOKEN_H

typedef enum {
    TOKEN_EOF,

    TOKEN_CLASS,
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_OBJECT_IDENTIFIER,

    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_SEMICOLON,

    TOKEN_ERROR  
} TokenType;

typedef struct {
    TokenType type;
    const char *start;
    int length;
    int line;
    int column;
} Token;

const char *token_type_name(TokenType type);

#endif