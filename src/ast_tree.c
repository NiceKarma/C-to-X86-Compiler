#include "ast_tree.h"
#include <stdlib.h>
#include <string.h>

Expression newExpression(int c) {
        Expression new_expr;
        new_expr.value = c;
        return new_expr;
}

Statement newReturn(Expression e) {
        Statement new_statement;
        new_statement.expression = e;
        return new_statement;
}

Function newFunction(char *name, Statement s) {
        Function new_function;
        new_function.name = (char *)malloc(strlen(name));
        new_function.name = name;
        new_function.statement = s;
        return new_function;
}

Program newProgram(Function f) {
        Program new_program;
        new_program.func = f;
        return new_program;
}
