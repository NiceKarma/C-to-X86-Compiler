#include "ast_tree.h"
#include "token_types.h"
#include <stdio.h>
/*
int generateExpression(Node *expression, FILE *dest) {
        switch (expression.type) {
        case MINUS:
                generateExpression(e, dest);
                fprintf(dest, "\tneg %%eax\n");
                break;
        case TILDE:
                generateExpression(*expression.expression, dest);
                fprintf(dest, "\tnot %%eax\n");
                break;
        case EXCLAMATION:
                generateExpression(*expression.expression, dest);
                fprintf(dest, "\tcmpl $0, %%eax\n");
                fprintf(dest, "\tmov $0, %%eax\n");
                fprintf(dest, "\tsete %%al\n");
                break;
        case INTEGER_LITERAL:
                fprintf(dest, "\tmovl $%d, %%eax\n", expression.value);
                break;
        }

        return 0;
}

int generateReturn(Node *statement, FILE *dest) {

        generateExpression(statement->child, dest);
        fprintf(dest, "\tret\n");

        return 0;
}

int generateFunc(Node *function, FILE *dest) {

        fprintf(dest, "\t.global %s\n", (char *)function->data);
        fprintf(dest, "%s:\n", (char *)function->data);

        generateReturn(function->child, dest);

        return 0;
}

int generateCode(Node *program, FILE *dest) {

        generateFunc(program->child, dest);

        return 0;
}
*/
