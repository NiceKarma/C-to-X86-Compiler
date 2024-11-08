#include "compiler.h"
#include "token_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int generateExpression(Expression expr, FILE *dest) {
        switch (expr.type) {
        case MINUS:
                generateExpression(*expr.expression, dest);
                fprintf(dest, "\tneg %%eax\n");
                break;
        case TILDE:
                generateExpression(*expr.expression, dest);
                fprintf(dest, "\tnot %%eax\n");
                break;
        case EXCLAMATION:
                generateExpression(*expr.expression, dest);
                fprintf(dest, "\tcmpl $0, %%eax\n");
                fprintf(dest, "\tmov $0, %%eax\n");
                fprintf(dest, "\tsete %%al\n");
                break;
        case INTEGER_LITERAL:
                fprintf(dest, "\tmovl $%d, %%eax\n", expr.value);
                break;
        }

        return 0;
}

int generateReturn(Statement statement, FILE *dest) {

        generateExpression(*statement.expression, dest);
        fprintf(dest, "\tret\n");

        return 0;
}

int generateFunc(Function func, FILE *dest) {

        fprintf(dest, "\t.global %s\n", func.name);
        fprintf(dest, "%s:\n", func.name);

        generateReturn(*func.statement, dest);

        return 0;
}

int generateCode(Program program, FILE *dest) {

        generateFunc(*program.func, dest);

        return 0;
}

Program tree;

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

        tree = parseProgram(&token_list);

        FILE *output_asm;
        output_asm = fopen("output.s", "w");
        if (output_asm == NULL) {
                printf("File failed to open!");
                exit(0);
        }

        generateCode(tree, output_asm);

        return 0;
}
