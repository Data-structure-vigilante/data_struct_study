#include "exprlinkedstack.h"
#include <ctype.h>
#include <string.h>

char *postFix(char *str) {
    char *result;
    LinkedStack *stack;
    StackNode node;
    int len = strlen(str);
    int idx = 0;

    stack = createLinkedStack();
    result = (char *)calloc(len + 1, sizeof(char));
    while (*str) {
        if (isalnum(*str))
            result[idx++] = *str;
        else {
            switch (*str) {
            case '+':
                while (peekLS(stack) && peekLS(stack)->data != '(') {
                    StackNode *temp;
                    temp = popLS(stack);
                    result[idx++] = temp->data;
                    free(temp);
                }
                node.data = *str;
                pushLS(stack, node);
                break;
            case '-':
                while (peekLS(stack) && peekLS(stack)->data != '(') {
                    StackNode *temp;
                    temp = popLS(stack);
                    result[idx++] = temp->data;
                    free(temp);
                }
                node.data = *str;
                pushLS(stack, node);
                break;
            case '*':
                while (peekLS(stack) && (peekLS(stack)->data == '*' ||
                                         peekLS(stack)->data == '/')) {
                    StackNode *temp;
                    temp = popLS(stack);
                    result[idx++] = temp->data;
                    free(temp);
                }
                node.data = *str;
                pushLS(stack, node);
                break;
            case '/':
                while (peekLS(stack) && (peekLS(stack)->data == '*' ||
                                         peekLS(stack)->data == '/')) {
                    StackNode *temp;
                    temp = popLS(stack);
                    result[idx++] = temp->data;
                    free(temp);
                }
                node.data = *str;
                pushLS(stack, node);
                break;
            case '(':
                node.data = *str;
                pushLS(stack, node);
                break;
            case ')':
                while (peekLS(stack) && peekLS(stack)->data != '(') {
                    StackNode *temp;
                    temp = popLS(stack);
                    result[idx++] = temp->data;
                    free(temp);
                }
                StackNode *temp;
                temp = popLS(stack);
                free(temp);
                break;
            }
        }
        str++;
    }
    while (!isLinkedStackEmpty(stack)) {
        StackNode *temp;
        temp = popLS(stack);
        result[idx++] = temp->data;
        free(temp);
    }
    deleteLinkedStack(stack);
    return result;
}

float calcExpression(char *str) {
    float ret;
    LinkedStack *stack;
    StackNode node;
    StackNode *temp1;
    StackNode *temp2;
    char *postFixExpression;

    postFixExpression = postFix(str);
    stack = createLinkedStack();
    char *current = postFixExpression;
    while (*current) {
        node.data = *current;
        if (isalnum(*current) != 0) {
            node.data = node.data - '0';
            pushLS(stack, node);
        } else {
            temp1 = popLS(stack);
            temp2 = popLS(stack);
            switch (*current) {
            case '+':
                node.data = temp1->data + temp2->data;
                break;
            case '*':
                node.data = temp1->data * temp2->data;
                break;
            case '-':
                node.data = temp2->data - temp1->data;
                break;
            case '/':
                node.data = temp2->data / temp1->data;
                break;
            default:
                break;
            }
            free(temp1);
            free(temp2);
            pushLS(stack, node);
        }
        ++current;
    }
    temp1 = popLS(stack);
    ret = temp1->data;
    free(temp1);
    deleteLinkedStack(stack);
    free(postFixExpression);
    return ret;
}