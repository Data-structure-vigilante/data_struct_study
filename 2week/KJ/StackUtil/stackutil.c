#include "stackutil.h"

int checkBracket(char *formula)
{
	LinkedStack *stack;

	stack = (LinkedStack *)calloc(1, sizeof(LinkedStack));

	if (formula == NULL)
		return ERROR;

	while (*formula)
	{
		if (*formula == '(' || *formula == '{' || *formula == '[')
		{
			StackNode element;
			element.data = *formula;
			pushLS(stack, element);
		}
		else if (*formula == ')')
		{
			if (stack->pTopElement == NULL || popLS(stack)->data != '(')
				return (FALSE);
		}
		else if (*formula == '}')
		{
			if (stack->pTopElement == NULL || popLS(stack)->data != '{')
				return (FALSE);
		}
		else if (*formula == ']')
		{
			if (stack->pTopElement == NULL || popLS(stack)->data != '[')
				return (FALSE);
		}
		++formula;
	}
	if (!isLinkedStackEmpty(stack))
		return (FALSE);
	return (TRUE);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("argument input error\n");
		return (-1);
	}
	if (checkBracket(av[1]))
		printf("Vaild Formula!\n");
	else
		printf("Invaild Formula!\n");
	return (0);
}