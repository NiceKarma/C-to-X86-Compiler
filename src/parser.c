#include "ast_tree.h"
#include "token_types.h"
#include <stdio.h>
#include <stdlib.h>

void syntaxError() {
        printf("Syntax Error!\n");
        exit(1);
}

Node *parseExpression(Token **);

Node *parseFactor(Token **input_token) {
        Token *curr_token = *input_token;

        Node *factor;

        if (curr_token->type == OPEN_PARENTHESIS) {
                curr_token++;
                factor = parseExpression(&curr_token);

                curr_token++;
                if (curr_token->type != CLOSE_PARENTHESIS) {
                        syntaxError();
                }

        } else if (curr_token->type == MINUS || curr_token->type == TILDE ||
                   curr_token->type == EXCLAMATION) {

                int op = curr_token->type;
                curr_token++;
                Node *inner_factor = parseFactor(&curr_token);
                factor = newUnOp(op, inner_factor);

        } else if (curr_token->type == INTEGER_LITERAL) {

                factor = newConstant(curr_token->type, curr_token->value);

        } else {
                syntaxError();
        }

        *input_token = curr_token;
        return factor;
}

Node *parseTerm(Token **input_token) {
        Token *curr_token = *input_token;

        Node *factor = parseFactor(&curr_token);
        Token *next_token = curr_token + 1;

        while (next_token->type == STAR || next_token->type == DIVIDE) {
                curr_token++;
                int op = curr_token->type;
                curr_token++;
                Node *next_factor = parseFactor(&curr_token);
                factor = newBinOp(op, factor, next_factor);
                next_token = curr_token + 1;
        }

        *input_token = curr_token;
        return factor;
}

Node *parseAdditiveExpression(Token **input_token) {
        Token *curr_token = *input_token;

        Node *term = parseTerm(&curr_token);
        Token *next_token = curr_token + 1;

        while (next_token->type == PLUS || next_token->type == MINUS) {
                curr_token++;
                int op = curr_token->type;
                curr_token++;
                Node *next_term = parseTerm(&curr_token);
                term = newBinOp(op, term, next_term);
                next_token = curr_token + 1;
        }

        *input_token = curr_token;
        return term;
}

Node *parseRelationalExpression(Token **input_token) {
        Token *curr_token = *input_token;

        Node *term = parseAdditiveExpression(&curr_token);
        Token *next_token = curr_token + 1;

        while (next_token->type == L_THAN || next_token->type == LE_THAN ||
               next_token->type == G_THAN || next_token->type == GE_THAN) {
                curr_token++;
                int op = curr_token->type;
                curr_token++;
                Node *next_term = parseAdditiveExpression(&curr_token);
                term = newBinOp(op, term, next_term);
                next_token = curr_token + 1;
        }

        *input_token = curr_token;
        return term;
}

Node *parseEqualityExpression(Token **input_token) {
        Token *curr_token = *input_token;

        Node *term = parseRelationalExpression(&curr_token);
        Token *next_token = curr_token + 1;

        while (next_token->type == IS_NOT_EQUAL ||
               next_token->type == IS_EQUAL) {
                curr_token++;
                int op = curr_token->type;
                curr_token++;
                Node *next_term = parseRelationalExpression(&curr_token);
                term = newBinOp(op, term, next_term);
                next_token = curr_token + 1;
        }

        *input_token = curr_token;
        return term;
}

Node *parseLogicalAndExpression(Token **input_token) {
        Token *curr_token = *input_token;

        Node *term = parseEqualityExpression(&curr_token);
        Token *next_token = curr_token + 1;

        while (next_token->type == LOGICAL_AND) {
                curr_token++;
                int op = curr_token->type;
                curr_token++;
                Node *next_term = parseEqualityExpression(&curr_token);
                term = newBinOp(op, term, next_term);
                next_token = curr_token + 1;
        }

        *input_token = curr_token;
        return term;
}

Node *parseExpression(Token **input_token) {
        Token *curr_token = *input_token;

        Node *term = parseLogicalAndExpression(&curr_token);
        Token *next_token = curr_token + 1;

        while (next_token->type == LOGICAL_OR) {
                curr_token++;
                int op = curr_token->type;
                curr_token++;
                Node *next_term = parseLogicalAndExpression(&curr_token);
                term = newBinOp(op, term, next_term);
                next_token = curr_token + 1;
        }

        *input_token = curr_token;
        return term;
}

Node *parseStatement(Token **input_token) {
        Token *curr_token = *input_token;

        if (curr_token->type != KEY_RETURN) {
                syntaxError();
        }

        // Passes the token after return keyword
        curr_token++;
        Node *expression = parseExpression(&curr_token);
        Node *statement = newReturn(expression);

        curr_token++;
        if (curr_token->type != SEMICOLON) {
                syntaxError();
        }

        *input_token = curr_token;
        return statement;
}

Node *parseFunction(Token **input_token) {
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
        Node *statement = parseStatement(&curr_token);
        Node *function = newFunction(func_name, statement);

        curr_token++;
        if (curr_token->type != CLOSE_CURLY) {
                syntaxError();
        }

        *input_token = curr_token;
        return function;
}
Node *parseProgram(Token **input_token) {
        Token *curr_token = *input_token;

        if (curr_token->type != START_OF_LIST) {
                syntaxError();
        }

        curr_token++;
        Node *function = parseFunction(&curr_token);
        Node *program = newProgram(function);

        *input_token = curr_token;
        return program;
}
