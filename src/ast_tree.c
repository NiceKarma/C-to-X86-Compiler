#include "ast_tree.h"
#include "token_types.h"
#include <stdlib.h>
#include <string.h>

Expression newUnOp(int operator, Expression * e) {
        Expression new_expr;
        new_expr.type = operator;
        new_expr.expression = (Expression *)malloc(sizeof(Expression));
        *new_expr.expression = *e;
        return new_expr;
}

Expression newConstant(int c) {
        Expression new_expr;
        new_expr.type = INTEGER_LITERAL;
        new_expr.value = c;
        new_expr.expression = NULL;
        return new_expr;
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
