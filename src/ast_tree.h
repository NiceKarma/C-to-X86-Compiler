#ifndef AST_TREE_DOT_H
#define AST_TREE_DOT_H

enum NodeTypes {
        PROGRAM_NODE,
        FUNCTION_NODE,
        RETURN_NODE,
        LITERAL_NODE,
        UNOP_NODE,
        BINOP_NODE
};

typedef struct Node {
        int type;
        void *data;
        struct Node *child;
        struct Node *sibling;
} Node;

typedef struct Function {
        char *name;
} Function;

typedef struct Literal {
        int ltype;
        char *value;
} Literal;

Node *newProgram(Node *);
Node *newFunction(const char *, Node *);
Node *newReturn(Node *);
Node *newConstant(int, const char *);
Node *newUnOp(int, Node *);
Node *newBinOp(int, Node *, Node *);

/*

typedef struct Factor {
        int type;
        char *value;
        void *child;
} Factor;

typedef struct Term {
        int type;
        char *value;
        void *child1;
        void *child2;
} Term;

typedef struct Expression {
        int type;
        char *value;
        void *child1;
        void *child2;
} Expression;

typedef struct Statement {
        Expression *expression;
} Statement;

typedef struct Function {
        char *name;
        Statement *statement;
} Function;

typedef struct Program {
        Function *func;
} Program;


Factor newUnOp(int, Factor *);

Factor newConstant(const char *);

Statement newReturn(Expression *);

Function newFunction(char *, Statement *);

Program newProgram(Function *);
*/

#endif
