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
        printf("str: %c\n", *str);
        if (isalnum(*str))
            result[idx++] = *str;
        else {
            switch (*str) {
            case '+':
                node.data = *str;
                pushLS(stack, node);
                break;
            case '-':
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
