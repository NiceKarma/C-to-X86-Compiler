#include "ast_tree.h"
#include "token_types.h"
#include <stdlib.h>
#include <string.h>

Node *newProgram(Node *f) {
        Node *node;
        node = (Node *)malloc(sizeof(Node));
        node->type = PROGRAM_NODE;
        node->data = NULL;
        node->child = f;
        node->sibling = NULL;

        return node;
}

Node *newFunction(const char *name, Node *s) {
        Node *node;
        node = (Node *)malloc(sizeof(Node));
        node->type = FUNCTION_NODE;

        Function *func;
        func = (Function *)malloc(sizeof(Function));
        func->name = (char *)malloc(strlen(name) + 1);
        strcpy(func->name, name);
        node->data = func;

        node->child = s;
        node->sibling = NULL;

        return node;
}

Node *newReturn(Node *e) {
        Node *node;
        node = (Node *)malloc(sizeof(Node));
        node->type = RETURN_NODE;
        node->data = NULL;
        node->child = e;
        node->sibling = NULL;

        return node;
}

Node *newConstant(int ltype, const char *v) {
        Node *node;
        node = (Node *)malloc(sizeof(Node));
        node->type = LITERAL_NODE;

        Literal *lit;
        lit = (Literal *)malloc(sizeof(Literal));
        lit->ltype = ltype;
        lit->value = (char *)malloc(strlen(v) + 1);
        strcpy(lit->value, v);
        node->data = lit;

        node->child = NULL;
        node->sibling = NULL;

        return node;
}

Node *newUnOp(int op, Node *f) {
        Node *node;
        node = (Node *)malloc(sizeof(Node));
        node->type = UNOP_NODE;
        node->data = (int *)malloc(sizeof(int));
        *(int *)node->data = op;
        node->child = f;
        node->sibling = NULL;

        return node;
}

Node *newBinOp(int op, Node *c1, Node *c2) {
        Node *node;
        node = (Node *)malloc(sizeof(Node));
        node->type = BINOP_NODE;
        node->data = (int *)malloc(sizeof(int));
        *(int *)node->data = op;
        node->child = c1;
        node->child->sibling = c2;
        node->sibling = NULL;

        return node;
}

/*
Term newBinOp(int op, void *c1, void *c2) {
        Term;
        new_expr.type = op;
        return new_expr;
}

Factor newUnOp(int op, Factor *f) {
        Factor new_factor;
        new_factor.type = op;
        return new_factor;
}

Factor newConstant(const char *str) {
        Factor new_factor;
        new_factor.type = INTEGER_LITERAL;
        new_factor.value = (char *)malloc(strlen(str) + 1);
        strcpy(new_factor.value, str);
        new_factor.child = NULL;
        return new_factor;
}

Statement newReturn(Expression *e) {
        Statement new_statement;
        new_statement.expression = (Expression *)malloc(sizeof(Expression));
        *new_statement.expression = *e;
        return new_statement;
}

Function newFunction(char *name, Statement *s) {
        Function new_function;
        new_function.name = (char *)malloc(strlen(name) + 1);
        strcpy(new_function.name, name);
        new_function.statement = (Statement *)malloc(sizeof(Statement));
        *new_function.statement = *s;
        return new_function;
}

Program newProgram(Function *f) {
        Program new_program;
        new_program.func = (Function *)malloc(sizeof(Function));
        *new_program.func = *f;
        return new_program;
}
*/
