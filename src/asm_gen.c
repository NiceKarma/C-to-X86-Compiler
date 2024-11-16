#include "ast_tree.h"
#include "token_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LabelCount {
        char *pref;
        unsigned int count;
};

char *labelGenerator(const char *prefix) {
        static struct LabelCount *list;
        static unsigned int list_length = 0;

        // To prevent buffer overflow later
        if (strlen(prefix) > 31) {
                return NULL;
        }

        // Initalization
        static int init = 1;
        if (init) {
                list = (struct LabelCount *)malloc(sizeof(struct LabelCount));
                init = 0;
        }

        for (unsigned int i = 0; i < list_length; i++) {
                if (!strcmp(list[i].pref, prefix)) {
                        list[i].count++;
                        char buffer[32];
                        int len =
                            sprintf(buffer, "%s_%04d", prefix, list[i].count);
                        char *ret_str = (char *)malloc(len + 1);
                        strcpy(ret_str, buffer);
                        return ret_str;
                }
        }

        list_length++;
        list[list_length - 1].pref = (char *)malloc(strlen(prefix) + 1);
        strcpy(list->pref, prefix);
        list[list_length - 1].count = 0;

        char buffer[32];
        int len = sprintf(buffer, "%s_0000", prefix);
        char *ret_str = (char *)malloc(len + 1);
        strcpy(ret_str, buffer);
        return ret_str;
}

int generateExpression(Node *, FILE *);

void e1rcx_e2rax(Node *e, FILE *dest) {
        generateExpression(e->child, dest);
        fprintf(dest, "\tpush %%rax\n");

        generateExpression(e->child->sibling, dest);
        fprintf(dest, "\tpop %%rcx\n");
}

void e1rax_e2rcx(Node *e, FILE *dest) {
        generateExpression(e->child->sibling, dest);
        fprintf(dest, "\tpush %%rax\n");

        generateExpression(e->child, dest);
        fprintf(dest, "\tpop %%rcx\n");
}

int generateExpression(Node *e, FILE *dest) {
        switch (e->type) {
        case UNOP_NODE:
                generateExpression(e->child, dest);

                switch (*(int *)e->data) {
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
                switch (*(int *)e->data) {
                case PLUS:
                        e1rcx_e2rax(e, dest);
                        fprintf(dest, "\tadd %%rcx, %%rax\n");
                        break;
                case MINUS:
                        e1rax_e2rcx(e, dest);
                        fprintf(dest, "\tsub %%rcx, %%rax\n");
                        break;
                case STAR:
                        e1rcx_e2rax(e, dest);
                        fprintf(dest, "\timul %%rcx, %%rax\n");
                        break;
                case DIVIDE:
                        e1rax_e2rcx(e, dest);
                        fprintf(dest, "\tmov $0, %%rdx\n");
                        fprintf(dest, "\tidiv %%rcx\n");
                        break;
                case IS_EQUAL:
                        e1rcx_e2rax(e, dest);
                        fprintf(dest, "\tcmp %%rax, %%rcx\n");
                        fprintf(dest, "\tmov $0, %%rax\n");
                        fprintf(dest, "\tsete %%al\n");
                        break;
                case IS_NOT_EQUAL:
                        e1rcx_e2rax(e, dest);
                        fprintf(dest, "\tcmp %%rax, %%rcx\n");
                        fprintf(dest, "\tmov $0, %%rax\n");
                        fprintf(dest, "\tsetne %%al\n");
                        break;
                case L_THAN:
                        e1rcx_e2rax(e, dest);
                        fprintf(dest, "\tcmp %%rax, %%rcx\n");
                        fprintf(dest, "\tmov $0, %%rax\n");
                        fprintf(dest, "\tsetl %%al\n");
                        break;
                case LE_THAN:
                        e1rcx_e2rax(e, dest);
                        fprintf(dest, "\tcmp %%rax, %%rcx\n");
                        fprintf(dest, "\tmov $0, %%rax\n");
                        fprintf(dest, "\tsetle %%al\n");
                        break;
                case G_THAN:
                        e1rcx_e2rax(e, dest);
                        fprintf(dest, "\tcmp %%rax, %%rcx\n");
                        fprintf(dest, "\tmov $0, %%rax\n");
                        fprintf(dest, "\tsetg %%al\n");
                        break;
                case GE_THAN:
                        e1rcx_e2rax(e, dest);
                        fprintf(dest, "\tcmp %%rax, %%rcx\n");
                        fprintf(dest, "\tmov $0, %%rax\n");
                        fprintf(dest, "\tsetge %%al\n");
                        break;
                case LOGICAL_OR:
                        generateExpression(e->child, dest);
                        fprintf(dest, "\tcmp $0, %%rax\n");
                        char *clause2 = labelGenerator("clause2");
                        char *end = labelGenerator("end");

                        fprintf(dest, "\tje %s\n", clause2);
                        fprintf(dest, "\tmov $1, %%rax\n");
                        fprintf(dest, "\tjmp %s\n", end);
                        fprintf(dest, "%s:\n", clause2);

                        generateExpression(e->child, dest);
                        fprintf(dest, "\tcmp $0, %%rax\n");
                        fprintf(dest, "\tmov $0, %%rax\n");
                        fprintf(dest, "\tsetne %%al\n");
                        fprintf(dest, "\t%s:\n", end);
                        break;
                }

                break;
        case LITERAL_NODE:
                switch (((Literal *)e->data)->ltype) {
                case INTEGER_LITERAL:
                        fprintf(dest, "\tmov $%s, %%rax\n",
                                ((Literal *)e->data)->value);
                        break;
                }
        }
        return 0;
}

int generateReturn(Node *s, FILE *dest) {

        generateExpression(s->child, dest);
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
