#ifndef COOL_TOKEN_H
#define COOL_TOKEN_H

typedef enum {
    TOKEN_EOF,

    TOKEN_CLASS,
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_OBJECT_IDENTIFIER,

    INT_CONST,

    TOKEN_LBRACE, // {
    TOKEN_RBRACE, // }
    TOKEN_LBRACKET, // [
    TOKEN_RBRACKET, // ]
    TOKEN_COMMA, // ,
    TOKEN_COLON, // :
    TOKEN_DOT,  // .
    TOKEN_AT, // @
    TOKEN_TILDE, // ~
    TOKEN_SEMICOLON, // ;

    TOKEN_PLUS, // + 
    TOKEN_MINUS, // -
    TOKEN_STAR, // *
    TOKEN_SLASH, // '/'
    TOKEN_LE, //LESS OR EQUAL
    TOKEN_ME,
    TOKEN_ASSIGN, // <-
    TOKEN_LT, // <
    TOKEN_MT,
    TOKEN_EQUAL, // =
    TOKEN_DARROW, // =>

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