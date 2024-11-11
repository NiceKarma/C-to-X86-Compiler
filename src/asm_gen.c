#include "ast_tree.h"
#include "token_types.h"
#include <stdio.h>

int generateFactor(Node *f, FILE *dest) {
        switch (f->type) {
        case UNOP_NODE:
                generateFactor(f->child, dest);

                switch (*(int *)f->data) {
                case MINUS:
                        fprintf(dest, "\tneg %%rax\n");
                        break;
                case TILDE:
                        fprintf(dest, "\tnot %%rax\n");
                        break;
                case EXCLAMATION:
                        fprintf(dest, "\tcmp $0, %%rax\n");
                        fprintf(dest, "\tmov $0, %%rax\n");
                        fprintf(dest, "\tsete %%al\n");
                        break;
                }
                break;
        case BINOP_NODE:
                generateFactor(f->child, dest);
                fprintf(dest, "\tpush %%rax\n");

                generateFactor(f->child->sibling, dest);
                fprintf(dest, "\tpop %%rcx\n");

                switch (*(int *)f->data) {
                case PLUS:
                        fprintf(dest, "\tadd %%rcx, %%rax\n");
                        break;
                case MINUS:
                        // Swap rax and rcx
                        fprintf(dest, "\tpush %%rax\n");
                        fprintf(dest, "\tpush %%rcx\n");
                        fprintf(dest, "\tpop %%rax\n");
                        fprintf(dest, "\tpop %%rcx\n");

                        fprintf(dest, "\tsub %%rcx, %%rax\n");
                        break;
                case STAR:
                        fprintf(dest, "\timul %%rcx, %%rax\n");
                        break;
                case DIVIDE:
                        // Swap rax and rcx
                        fprintf(dest, "\tpush %%rax\n");
                        fprintf(dest, "\tpush %%rcx\n");
                        fprintf(dest, "\tpop %%rax\n");
                        fprintf(dest, "\tpop %%rcx\n");

                        fprintf(dest, "\tmov $0, %%rdx\n");
                        fprintf(dest, "\tidiv %%rcx\n");
                        break;
                }

                break;
        case LITERAL_NODE:
                switch (((Literal *)f->data)->ltype) {
                case INTEGER_LITERAL:
                        fprintf(dest, "\tmov $%s, %%rax\n",
                                ((Literal *)f->data)->value);
                        break;
                }
        }
        return 0;
}

int generateReturn(Node *s, FILE *dest) {

        generateFactor(s->child, dest);
        fprintf(dest, "\tret\n");

        return 0;
}

int generateFunc(Node *f, FILE *dest) {

        fprintf(dest, "\t.global %s\n", ((Function *)f->data)->name);
        fprintf(dest, "%s:\n", ((Function *)f->data)->name);

        generateReturn(f->child, dest);

        return 0;
}

int generateCode(Node *p, FILE *dest) {

        generateFunc(p->child, dest);

        return 0;
}

/*
int generateTerm(Node *t, FILE *dest) {
        generateFactor(t->child, dest);
        if (t->type == BINOP_NODE) {
                switch (*(int *)t->data) {
                case STAR:
                        break;
                case DIVIDE:
                        break;
                }
        }

        return 0;
}

// e = unop(-, 1)
int generateExpression(Node *e, FILE *dest) {
        generateTerm(e->child, dest);
        if (e->type == BINOP_NODE) {
                switch (*(int *)e->data) {
                case PLUS:
                        generateTerm(e->child, dest);
                        // print asm
                        break;
                case MINUS:
                        generateTerm(e->child, dest);
                        // print asm
                        break;
                }
        }

        return 0;
}
*/
