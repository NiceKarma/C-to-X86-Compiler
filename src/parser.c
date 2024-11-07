#include "ast_tree.h"
#include "token_types.h"
#include <stdio.h>
#include <stdlib.h>

void syntaxError() {
        printf("Syntax Error!\n");
        exit(1);
}

Expression parseExpression(Token **input_token) {
        Token *curr_token = *input_token;

        if (curr_token->type != INTEGER_LITERAL) {
                syntaxError();
        }

        Expression expr;
        expr.value = atoi(curr_token->value);

        *input_token = curr_token;
        return expr;
}

Statement parseStatement(Token **input_token) {
        Token *curr_token = *input_token;

        curr_token++;
        if (curr_token->type != KEY_RETURN) {
                syntaxError();
        }

        curr_token++;
        if (curr_token->type != INTEGER_LITERAL) {
                syntaxError();
        }

        Expression expr = parseExpression(&curr_token);
        Statement statement = newReturn(expr);

        curr_token++;
        if (curr_token->type != SEMICOLON) {
                syntaxError();
        }

        *input_token = curr_token;
        return statement;
}

Function parseFunction(Token **input_token) {
        Token *curr_token = *input_token;
        curr_token++;
        if (curr_token->type != KEY_INT) {
                syntaxError();
        }

        curr_token++;
        if (curr_token->type != IDENTIFIER) {
                syntaxError();
        }
        char *func_name = curr_token->value;

        curr_token++;
        if (curr_token->type != OPEN_PARENTHESIS) {
                syntaxError();
        }

        curr_token++;
        if (curr_token->type != CLOSE_PARENTHESIS) {
                syntaxError();
        }

        curr_token++;
        if (curr_token->type != OPEN_CURLY) {
                syntaxError();
        }

        Statement statement = parseStatement(&curr_token);
        Function func = newFunction(func_name, statement);

        curr_token++;
        if (curr_token->type != CLOSE_CURLY) {
                syntaxError();
        }

        *input_token = curr_token;
        return func;
}

Program parseProgram(Token **input_token) {
        Token *curr_token = *input_token;
        if (curr_token->type != START_OF_LIST) {
                syntaxError();
        }
        Function func = parseFunction(&curr_token);
        Program prog = newProgram(func);

        *input_token = curr_token;
        return prog;
}
