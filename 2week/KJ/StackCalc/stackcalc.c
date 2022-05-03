#include "linkedstack.h"
#include <string.h>

int getPrecOp(char op)
{
	if (op == '*' || op == '/')
		return (3);
	if (op == '+' || op == '-')
		return (2);
	return (1);
}

char *stackCalc(char *formula)
{
	char *answer;
	LinkedStack *stack;
	int len;
	int i;
	StackNode element;
	Operator op;

	i = 0;
	len = strlen(formula);
	stack = (LinkedStack *)calloc(1, sizeof(LinkedStack));
	if (stack == NULL)
		return (NULL);
	answer = (char *)calloc(len + 1, sizeof(char));
	if (answer == NULL)
		return (NULL);

	while (*formula)
	{
		if (*formula == '(')
		{
			op.type = *formula;
			op.precedence = getPrecOp(*formula);
			element.data = op;
			pushLS(stack, element);
		}
		else if (*formula == ')')
		{
			while (peekLS(stack)->data.type != '(')
				answer[i++] = popLS(stack)->data.type;
			popLS(stack);
		}
		else if (*formula == '+' || *formula == '-' || *formula == '*' || *formula == '/')
		{
			op.type = *formula;
			op.precedence = getPrecOp(*formula);
			element.data = op;
			if (isLinkedStackEmpty(stack))
				pushLS(stack, element);
			else
			{
				while (op.precedence <= peekLS(stack)->data.precedence)
				{
					answer[i++] = popLS(stack)->data.type;
					if (isLinkedStackEmpty(stack))
						break;
				}
				pushLS(stack, element);
			}
		}
		else
			answer[i++] = *formula;
		formula++;
	}
	while (!isLinkedStackEmpty(stack))
		answer[i++] = popLS(stack)->data.type;
	return (answer);
}

int main(int ac, char **av)
{
	printf("%s\n", stackCalc(av[1]));
	return (0);
}