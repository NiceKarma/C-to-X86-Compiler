#include "compiler.h"
#include "token_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TokenList {
        Token *token;
        int len;
} TokenList;

void *safeMalloc(int);

void *safeRealloc(void *, int);

int isKeyword(char *);

char peakChar(FILE *f) {
        char c = fgetc(f);
        fseek(f, -1, SEEK_CUR);
        return c;
}

int isAlpha(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                return 1;
        }
        return 0;
}

int isNum(char c) {
        if (c >= '0' && c <= '9') {
                return 1;
        }
        return 0;
}

int isAlphaNumeric(char c) {
        if (isAlpha(c) || isNum(c)) {
                return 1;
        }
        return 0;
}

Token *lex(FILE *f) {
        char current_char;
        int list_len = 1;
        Token *token_list;
        token_list = safeMalloc(sizeof(Token));
        token_list->type = START_OF_LIST;

        while (1) {
                current_char = fgetc(f);
                if (current_char == '\n' || current_char == ' ' ||
                    current_char == '\t') {
                        continue;
                }
                list_len++;
                token_list = safeRealloc(token_list, list_len * sizeof(Token));
                token_list[list_len - 1].value = NULL;

                if (current_char == EOF) {
                        token_list[list_len - 1].type = END_OF_LIST;
                        break;
                }

                if (isAlpha(current_char) || (current_char == '_')) {

                        int word_len = 2;
                        token_list[list_len - 1].value =
                            safeMalloc(word_len * sizeof(char));
                        token_list[list_len - 1].value[0] = current_char;

                        while (isAlphaNumeric(peakChar(f)) ||
                               (peakChar(f) == '_')) {
                                current_char = fgetc(f);

                                word_len++;
                                token_list[list_len - 1].value =
                                    safeRealloc(token_list[list_len - 1].value,
                                                word_len * sizeof(char));
                                ((token_list + list_len - 1)
                                     ->value)[word_len - 2] = current_char;

                                if (word_len == 64) {
                                        printf(
                                            "Keyword/identifier too long!\n");
                                        abort();
                                }
                        }

                        (token_list[list_len - 1].value)[word_len - 1] = '\0';

                        if (isKeyword(token_list[list_len - 1].value)) {
                                token_list[list_len - 1].type =
                                    isKeyword(token_list[list_len - 1].value);
                        } else {
                                token_list[list_len - 1].type = IDENTIFIER;
                        }

                        continue;
                }

                if (isAlphaNumeric(current_char)) {
                        int num_len = 2;
                        token_list[list_len - 1].value =
                            safeMalloc(num_len * sizeof(char));
                        (token_list[list_len - 1].value)[0] = current_char;
                        current_char = fgetc(f);

                        while (isAlphaNumeric(current_char)) {
                                num_len++;
                                token_list[list_len - 1].value =
                                    safeRealloc(token_list[list_len - 1].value,
                                                num_len * sizeof(char));
                                ((token_list + list_len - 1)
                                     ->value)[num_len - 2] = current_char;
                                if (num_len == 64) {
                                        printf("Number too long!\n");
                                        abort();
                                }
                                current_char = fgetc(f);
                        }

                        fseek(f, -1, SEEK_CUR);
                        (token_list[list_len - 1].value)[num_len - 1] = '\0';
                        token_list[list_len - 1].type = INTEGER_LITERAL;

                        continue;
                }

                switch (current_char) {
                case '{':
                        token_list[list_len - 1].type = OPEN_CURLY;
                        break;
                case '}':
                        token_list[list_len - 1].type = CLOSE_CURLY;
                        break;
                case '(':
                        token_list[list_len - 1].type = OPEN_PARENTHESIS;
                        break;
                case ')':
                        token_list[list_len - 1].type = CLOSE_PARENTHESIS;
                        break;
                case '[':
                        token_list[list_len - 1].type = OPEN_BRACKET;
                        break;
                case ']':
                        token_list[list_len - 1].type = CLOSE_BRACKET;
                        break;
                case ';':
                        token_list[list_len - 1].type = SEMICOLON;
                        break;
                case '=':
                        if (peakChar(f) == '=') {
                                token_list[list_len - 1].type = IS_EQUAL;
                                fgetc(f);
                                break;
                        }
                        token_list[list_len - 1].type = EQUALS;
                        break;
                case '+':
                        token_list[list_len - 1].type = PLUS;
                        break;
                case '-':
                        token_list[list_len - 1].type = MINUS;
                        break;
                case '*':
                        token_list[list_len - 1].type = STAR;
                        break;
                case '/':
                        token_list[list_len - 1].type = DIVIDE;
                        break;
                case '~':
                        token_list[list_len - 1].type = TILDE;
                        break;
                case '!':
                        if (peakChar(f) == '=') {
                                token_list[list_len - 1].type = IS_NOT_EQUAL;
                                fgetc(f);
                                break;
                        }
                        token_list[list_len - 1].type = EXCLAMATION;
                        break;
                case '%':
                        token_list[list_len - 1].type = MODULO;
                        break;
                case '<':
                        if (peakChar(f) == '=') {
                                token_list[list_len - 1].type = LE_THAN;
                                fgetc(f);
                                break;
                        }
                        token_list[list_len - 1].type = L_THAN;
                        break;
                case '>':
                        if (peakChar(f) == '=') {
                                token_list[list_len - 1].type = GE_THAN;
                                fgetc(f);
                                break;
                        }
                        token_list[list_len - 1].type = G_THAN;
                        break;
                case '&':
                        if (peakChar(f) == '&') {
                                token_list[list_len - 1].type = LOGICAL_AND;
                                fgetc(f);
                                break;
                        }
                        token_list[list_len - 1].type = BITWISE_AND;
                        break;
                case '|':
                        if (peakChar(f) == '|') {
                                token_list[list_len - 1].type = LOGICAL_OR;
                                fgetc(f);
                                break;
                        }
                        token_list[list_len - 1].type = BITWISE_OR;
                        break;
                case '"':
                        token_list[list_len - 1].type = STRING_LITERAL;
                        int str_len = 1;
                        token_list[list_len - 1].value =
                            safeMalloc(sizeof(char));
                        while (1) {
                                current_char = fgetc(f);

                                if (current_char == '"') {
                                        ((token_list + list_len - 1)
                                             ->value)[str_len - 1] = '\0';
                                        break;
                                } else {
                                        str_len++;
                                        (token_list + list_len - 1)->value =
                                            safeRealloc(
                                                token_list[list_len - 1].value,
                                                str_len * sizeof(char));
                                        ((token_list + list_len - 1)
                                             ->value)[str_len - 2] =
                                            current_char;
                                }
                        }
                        break;

                default:

                        continue;
                }
        }
        return token_list;
}

void *safeMalloc(int size) {
        void *tmp_ptr;
        tmp_ptr = malloc(size);
        if (tmp_ptr == NULL) {
                printf("Pointer Allocation failed!\n");
                abort();
        }
        return tmp_ptr;
}

void *safeRealloc(void *ptr, int size) {
        void *tmp_ptr;
        tmp_ptr = realloc(ptr, size);
        if (tmp_ptr == NULL) {
                printf("Pointer Reallocation failed!\n");
                abort();
        }
        return tmp_ptr;
}

int isKeyword(char *string) {
        if (!strcmp(string, "auto")) {
                return KEY_AUTO;
        }
        if (!strcmp(string, "break")) {
                return KEY_BREAK;
        }
        if (!strcmp(string, "case")) {
                return KEY_CASE;
        }
        if (!strcmp(string, "char")) {
                return KEY_CHAR;
        }
        if (!strcmp(string, "const")) {
                return KEY_CONST;
        }
        if (!strcmp(string, "continue")) {
                return KEY_CONTINUE;
        }
        if (!strcmp(string, "default")) {
                return KEY_DEFAULT;
        }
        if (!strcmp(string, "do")) {
                return KEY_DO;
        }
        if (!strcmp(string, "double")) {
                return KEY_DOUBLE;
        }
        if (!strcmp(string, "else")) {
                return KEY_ELSE;
        }
        if (!strcmp(string, "enum")) {
                return KEY_ENUM;
        }
        if (!strcmp(string, "extern")) {
                return KEY_EXTERN;
        }
        if (!strcmp(string, "float")) {
                return KEY_FLOAT;
        }
        if (!strcmp(string, "for")) {
                return KEY_FOR;
        }
        if (!strcmp(string, "goto")) {
                return KEY_GOTO;
        }
        if (!strcmp(string, "if")) {
                return KEY_IF;
        }
        if (!strcmp(string, "int")) {
                return KEY_INT;
        }
        if (!strcmp(string, "long")) {
                return KEY_LONG;
        }
        if (!strcmp(string, "register")) {
                return KEY_REGISTER;
        }
        if (!strcmp(string, "return")) {
                return KEY_RETURN;
        }
        if (!strcmp(string, "short")) {
                return KEY_SHORT;
        }
        if (!strcmp(string, "signed")) {
                return KEY_SIGNED;
        }
        if (!strcmp(string, "sizeof")) {
                return KEY_SIZEOF;
        }
        if (!strcmp(string, "static")) {
                return KEY_STATIC;
        }
        if (!strcmp(string, "struct")) {
                return KEY_STRUCT;
        }
        if (!strcmp(string, "switch")) {
                return KEY_SWITCH;
        }
        if (!strcmp(string, "typedef")) {
                return KEY_TYPEDEF;
        }
        if (!strcmp(string, "union")) {
                return KEY_UNION;
        }
        if (!strcmp(string, "unsigned")) {
                return KEY_UNSIGNED;
        }
        if (!strcmp(string, "void")) {
                return KEY_VOID;
        }
        if (!strcmp(string, "volatile")) {
                return KEY_VOLATILE;
        }
        if (!strcmp(string, "while")) {
                return KEY_WHILE;
        }

        return 0;
}
