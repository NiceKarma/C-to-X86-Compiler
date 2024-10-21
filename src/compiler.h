#ifndef COMPILER_FUNCTIONS
#define COMPILER_FUNCTIONS

#include <stdio.h>

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
        INTEGER_LITERAL,
        FLOAT_LITEREAL,
        CHARACTER_LITERAL,
        STRING_LITERAL,
        COMMENT,
        WHITESPACE,
        END_OF_LIST
};

typedef struct {
        unsigned int type;
        char *value;
} Token;

/*
 * TreeNode struct for tree data structure using the child/sibling type.
 * value - the value to be store in the structure
 * child - the first child of the node
 * sibling - the sibling of the node
 */
typedef struct TreeNode {
        int value;
        struct TreeNode *child;
        struct TreeNode *sibling;
} TreeNode;

void *safeMalloc(int);

void *safeRealloc(void *, int);

int isKeyword(char *);

Token *lex(FILE *);

#endif
