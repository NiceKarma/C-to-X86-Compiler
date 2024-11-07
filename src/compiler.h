#ifndef COMPILER_FUNCTIONS_DOT_H
#define COMPILER_FUNCTIONS_DOT_H

#include "ast_tree.h"
#include "token_types.h"
#include <stdio.h>

Token *lex(FILE *);

Program parseProgram(Token **);

#endif
