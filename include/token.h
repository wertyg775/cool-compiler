#ifndef COOL_TOKEN_H
#define COOL_TOKEN_H

typedef enum {
    TOKEN_EOF,

    TOKEN_CLASS,
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_OBJECT_IDENTIFIER,

    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_FI,
    TOKEN_IN,
    TOKEN_INHERITS,
    TOKEN_ISVOID,
    TOKEN_LET,
    TOKEN_LOOP,
    TOKEN_POOL,
    TOKEN_THEN,
    TOKEN_WHILE,
    TOKEN_CASE,
    TOKEN_ESAC,
    TOKEN_NEW,
    TOKEN_OF,
    TOKEN_NOT,
    TOKEN_BOOL_CONST,

    INT_CONST,
    STR_CONST,

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
    TOKEN_LE, // <=
    TOKEN_GE, // >=
    TOKEN_ASSIGN, // <-
    TOKEN_LT, // <
    TOKEN_GT, // >
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