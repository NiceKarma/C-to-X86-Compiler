#include "compiler.h"
#include "token_types.h"
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

        // Tokenize file
        token_list = lex(file_to_lex);

        fclose(file_to_lex);

        // Parse Phase
        Node *tree = parseProgram(&token_list);

        printAST(tree);

        FILE *output_asm;
        output_asm = fopen("output.s", "w");
        if (output_asm == NULL) {
                printf("File failed to open!");
                exit(0);
        }

        // generateCode(tree, output_asm);

        fclose(output_asm);

        return 0;
}
