#ifndef EXPRLINKEDSTACK_H
#define EXPRLINKEDSTACK_H

#include "linkedStack.h"

typedef enum PrecedenceType {
    lparen,
    rparen,
    times,
    divide,
    plus,
    minus,
    operand
} Precedence;

typedef struct ExprTokenType {
    float value;
    Precedence type;
} ExprToken;
char *postFix(char *str);
float calcExpression(char *str);
#endif