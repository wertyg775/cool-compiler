#include "token.h"

const char *token_type_name(TokenType type) {
    switch (type) {
        case TOKEN_EOF:
            return "TOKEN_EOF";
        case TOKEN_CLASS:
            return "TOKEN_CLASS";
        case TOKEN_TYPE_IDENTIFIER:
            return "TOKEN_TYPE_IDENTIFIER";
        case TOKEN_OBJECT_IDENTIFIER:
            return "TOKEN_OBJECT_IDENTIFIER";
        case TOKEN_LBRACE:
            return "TOKEN_LBRACE";
        case TOKEN_RBRACE:
            return "TOKEN_RBRACE";
        case TOKEN_LBRACKET:
            return "TOKEN_LBRACKET";
        case TOKEN_RBRACKET:
            return "TOKEN_RBRACKET";    
        case TOKEN_COMMA:
            return "TOKEN_COMMA";
        case TOKEN_DOT:
            return "TOKEN_DOT";
        case TOKEN_SEMICOLON:
            return "TOKEN_SEMICOLON";
        case TOKEN_ERROR:
            return "TOKEN_ERROR";
        default:
            return "TOKEN_UNKNOWN";
    }
}