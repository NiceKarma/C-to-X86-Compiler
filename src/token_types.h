#ifndef _TOKEN_TYPES_DOT_H_
#define _TOKEN_TYPES_DOT_H_

enum TokenTypes {
        START_OF_LIST = 1,
        IDENTIFIER,

        KEYWORDS_START,
        KEY_AUTO,
        KEY_BREAK,
        KEY_CASE,
        KEY_CHAR,
        KEY_CONST,
        KEY_CONTINUE,
        KEY_DEFAULT,
        KEY_DO,
        KEY_DOUBLE,
        KEY_ELSE,
        KEY_ENUM,
        KEY_EXTERN,
        KEY_FLOAT,
        KEY_FOR,
        KEY_GOTO,
        KEY_IF,
        KEY_INT,
        KEY_LONG,
        KEY_REGISTER,
        KEY_RETURN,
        KEY_SHORT,
        KEY_SIGNED,
        KEY_SIZEOF,
        KEY_STATIC,
        KEY_STRUCT,
        KEY_SWITCH,
        KEY_TYPEDEF,
        KEY_UNION,
        KEY_UNSIGNED,
        KEY_VOID,
        KEY_VOLATILE,
        KEY_WHILE,
        KEYWORDS_END,

        OPEN_CURLY,
        CLOSE_CURLY,
        OPEN_PARENTHESIS,
        CLOSE_PARENTHESIS,
        OPEN_BRACKET,
        CLOSE_BRACKET,
        SEMICOLON,

        EQUALS,

        PLUS,
        MINUS,
        STAR,
        DIVIDE,
        MODULO,
        TILDE,
        EXCLAMATION,

        IS_EQUAL,
        IS_NOT_EQUAL,
        L_THAN,
        LE_THAN,
        G_THAN,
        GE_THAN,

        LOGICAL_AND,
        LOGICAL_OR,
        BITWISE_AND,
        BITWISE_OR,

        INTEGER_LITERAL,
        FLOAT_LITERAL,
        CHARACTER_LITERAL,
        STRING_LITERAL,
        END_OF_LIST
};

typedef struct {
        unsigned int type;
        char *value;
} Token;

#endif
