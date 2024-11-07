#include "compiler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

        if (argc != 2) {
                printf("Incorrect number of arguments!");
                exit(0);
        }

        FILE *file_to_lex;
        file_to_lex = fopen(argv[1], "r");
        if (file_to_lex == NULL) {
                printf("File failed to open!");
                exit(0);
        }

        Token *token_list;

        token_list = lex(file_to_lex);
        for (int i = 0; token_list[i].type != END_OF_LIST; i++) {
                printf("%d, ", token_list[i].type);
                switch (token_list[i].type) {
                case STRING_LITERAL:
                        printf("\"%s\"\n", token_list[i].value);
                        break;
                case IDENTIFIER:
                case INTEGER_LITERAL:
                        printf("%s\n", token_list[i].value);
                        break;
                default:
                        printf("\n");
                }
        }
        fclose(file_to_lex);

        Program tree = parseProgram(&token_list);

        return 0;
}
