#include "print_ast.h"
#include "ast_tree.h"
#include "token_types.h"
#include <stdio.h>

void printTabs(int num_tabs) {
        for (int i = 0; i < num_tabs; i++) {
                printf("|   ");
        }
}

void printFactor(Node *factor, int curr_lvl) {
        printTabs(curr_lvl);
        printf("%s\n", typeString(((Literal *)factor->data)->ltype));
        if (((Literal *)factor->data)->ltype == INTEGER_LITERAL) {
                printTabs(curr_lvl);
                printf("  = %s\n", ((Literal *)factor->data)->value);
        }
        if (factor->child == NULL) {
                return;
        }
        printFactor(factor->child, curr_lvl + 1);
        if (factor->child->sibling == NULL) {
                return;
        }
        printFactor(factor->child->sibling, curr_lvl + 1);
}

void printStatement(Node *statement, int curr_lvl) {
        printTabs(curr_lvl);
        printf("Return: \n");

        printFactor(statement->child, curr_lvl + 1);
}

void printFunc(Node *function, int curr_lvl) {
        printTabs(curr_lvl);
        printf("Function int %s:\n", ((Function *)function->data)->name);

        curr_lvl++;
        printTabs(curr_lvl);
        printf("Params: \n");

        printTabs(curr_lvl);
        printf("Body: \n");

        printStatement(function->child, curr_lvl + 1);
}

void printAST(Node *program) {
        int curr_lvl = 0;
        printf("Program:\n");

        printFunc(program->child, curr_lvl);
}

char *typeString(int type) {
        switch (type) {
        case (START_OF_LIST):
                return "START_OF_LIST";

        case (IDENTIFIER):
                return "Identifier";

        case (KEY_AUTO):
                return "Keyword: auto";
        case (KEY_BREAK):
                return "Keyword: break";
        case (KEY_CASE):
                return "Keyword: case";
        case (KEY_CHAR):
                return "Keyword: char";
        case (KEY_CONST):
                return "Keyword: const";
        case (KEY_CONTINUE):
                return "Keyword: continue";
        case (KEY_DEFAULT):
                return "Keyword: default";
        case (KEY_DO):
                return "Keyword: do";
        case (KEY_DOUBLE):
                return "Keyword: double";
        case (KEY_ELSE):
                return "Keyword: else";
        case (KEY_ENUM):
                return "Keyword: enum";
        case (KEY_EXTERN):
                return "Keyword: extern";
        case (KEY_FLOAT):
                return "Keyword: float";
        case (KEY_FOR):
                return "Keyword: for";
        case (KEY_GOTO):
                return "Keyword: goto";
        case (KEY_IF):
                return "Keyword: if";
        case (KEY_INT):
                return "Keyword: int";
        case (KEY_LONG):
                return "Keyword: long";
        case (KEY_REGISTER):
                return "Keyword: register";
        case (KEY_RETURN):
                return "Keyword: return";
        case (KEY_SHORT):
                return "Keyword: short";
        case (KEY_SIGNED):
                return "Keyword: signed";
        case (KEY_SIZEOF):
                return "Keyword: sizeof";
        case (KEY_STATIC):
                return "Keyword: static";
        case (KEY_STRUCT):
                return "Keyword: struct";
        case (KEY_SWITCH):
                return "Keyword: switch";
        case (KEY_TYPEDEF):
                return "Keyword: typedef";
        case (KEY_UNION):
                return "Keyword: union";
        case (KEY_UNSIGNED):
                return "Keyword: unsigned";
        case (KEY_VOID):
                return "Keyword: void";
        case (KEY_VOLATILE):
                return "Keyword: volatile";
        case (KEY_WHILE):
                return "Keyword: while";

        case (OPEN_CURLY):
                return "OPEN_CURLY";
        case (CLOSE_CURLY):
                return "CLOSE_CURLY";
        case (OPEN_PARENTHESIS):
                return "OPEN_PARENTHESIS";
        case (CLOSE_PARENTHESIS):
                return "CLOSE_PARENTHESIS";
        case (OPEN_BRACKET):
                return "OPEN_BRACKET";
        case (CLOSE_BRACKET):
                return "CLOSE_BRACKET";
        case (SEMICOLON):
                return "SEMICOLON";

        case (EQUALS):
                return "EQUALS";

        case (PLUS):
                return "PLUS";
        case (MINUS):
                return "MINUS";
        case (STAR):
                return "STAR";
        case (DIVIDE):
                return "DIVIDE";
        case (MODULO):
                return "MODULO";
        case (TILDE):
                return "TILDE";
        case (EXCLAMATION):
                return "EXCLAMATION";

        case (IS_EQUAL):
                return "IS_EQUAL";
        case (IS_NOT_EQUAL):
                return "IS_NOT_EQUAL";
        case (L_THAN):
                return "L_THAN";
        case (LE_THAN):
                return "LE_THAN";
        case (G_THAN):
                return "G_THAN";
        case (GE_THAN):
                return "GE_THAN";

        case (LOGICAL_AND):
                return "LOGICAL_AND";
        case (LOGICAL_OR):
                return "LOGICAL_OR";
        case (BITWISE_AND):
                return "BITWISE_AND";
        case (BITWISE_OR):
                return "BITWISE_OR";

        case (INTEGER_LITERAL):
                return "INTEGER_LITERAL\0";
        case (FLOAT_LITERAL):
                return "FLOAT_LITERAL";
        case (CHARACTER_LITERAL):
                return "CHARACTER_LITERAL";
        case (STRING_LITERAL):
                return "STRING_LITERAL";

        case (END_OF_LIST):
                return "END_OF_LIST";
        }

        return NULL;
}
