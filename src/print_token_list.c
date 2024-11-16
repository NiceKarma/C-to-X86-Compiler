#include "print_ast.h"
#include "token_types.h"
#include <stdio.h>
#include <string.h>

void printTokenList(Token **t) {
        Token *token = *t;
        int curr;
        while (token[curr].type != END_OF_LIST) {
                printf("#: %d\tType: %s", curr, typeString(token[curr].type));
                if (token[curr].value != NULL) {
                        printf("\t\tValue: %s", token[curr].value);
                }
                printf("\n");
                curr++;
        }
        printf("#: %d\tType: %s\n", curr, typeString(token[curr].type));
}
