#ifndef AST_TREE_DOT_H
#define AST_TREE_DOT_H

typedef struct Expression {
        int value;
} Expression;

typedef struct Statement {
        Expression expression;
} Statement;

typedef struct Function {
        char *name;
        Statement statement;
} Function;

typedef struct Program {
        Function func;
} Program;

Expression newExpression(int);

Statement newReturn(Expression);

Function newFunction(char *, Statement);

Program newProgram(Function);

#endif
