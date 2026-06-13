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
        case INT_CONST:
            return "INT_CONST";
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
        case TOKEN_AT:
            return "TOKEN_AT";
        case TOKEN_TILDE:
            return "TOKEN_TILDE";
        case TOKEN_SEMICOLON:
            return "TOKEN_SEMICOLON";
        case TOKEN_PLUS:
            return "TOKEN_PLUS";
        case TOKEN_MINUS:
            return "TOKEN_MINUS";
        case TOKEN_STAR:
            return "TOKEN_STAR";
        case TOKEN_SLASH:
            return "TOKEN_SLASH";
        case TOKEN_LE:
            return "TOKEN_LE";
        case TOKEN_ME:
            return "TOKEN_ME";
        case TOKEN_ASSIGN:
            return "TOKEN_ASSIGN";
        case TOKEN_LT:
            return "TOKEN_LT";
        case TOKEN_MT:
            return "TOKEN_MT";
        case TOKEN_EQUAL:
            return "TOKEN_EQUAL";
        case TOKEN_ERROR:
            return "TOKEN_ERROR";
        default:
            return "TOKEN_UNKNOWN";
    }
}