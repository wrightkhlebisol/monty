#include "monty.h"

/**
 * pstr - prints string starting @ the top of stack
 * @head: the pointer to the head node of the pointer
 * @line_number: the line number
 *
 * Return: void
 */
void pstr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	int num;
	stack_t *temp;

	if ((*head) == NULL)
	{
		putchar('\n');
	}

	temp = (*head);

	while (temp)
	{
		num = temp->n;

		if (num == 0)
			break;
		if (!(num >= 0 && num <= 127))
			break;
		if (num > 0 && num < 128)
		{
			printf("%c", num);
		}
		temp = temp->next;
	}
	putchar('\n');
}
