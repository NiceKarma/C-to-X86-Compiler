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
        Expression expr;

        if (curr_token->type == INTEGER_LITERAL) {

                expr = newConstant(atoi(curr_token->value));

        } else if (curr_token->type == MINUS || curr_token->type == TILDE ||
                   curr_token->type == EXCLAMATION) {

                Token *orig_token = curr_token;
                curr_token++;
                Expression inner_expr = parseExpression(&curr_token);
                expr = newUnOp(orig_token->type, &inner_expr);

        } else {
                syntaxError();
        }

        *input_token = curr_token;
        return expr;
}

Statement parseStatement(Token **input_token) {
        Token *curr_token = *input_token;

        if (curr_token->type != KEY_RETURN) {
                syntaxError();
        }

        curr_token++;
        Expression expr = parseExpression(&curr_token);
        Statement statement = newReturn(&expr);

        curr_token++;
        if (curr_token->type != SEMICOLON) {
                syntaxError();
        }

        *input_token = curr_token;
        return statement;
}

Function parseFunction(Token **input_token) {
        Token *curr_token = *input_token;
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

        curr_token++;
        Statement statement = parseStatement(&curr_token);
        Function func = newFunction(func_name, &statement);

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
        curr_token++;
        Function func = parseFunction(&curr_token);
        Program prog = newProgram(&func);

        *input_token = curr_token;
        return prog;
}
