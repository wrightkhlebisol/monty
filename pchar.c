#include "monty.h"

/**
 * pchar - prints char @top of stack
 * @head: the pointer to the head node of the pointer
 * @line_number: the line number
 *
 * Return: void
 */
void pchar(stack_t **head, unsigned int line_number)
{
	int num, i;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*head)->n;

	if (!(num >= 0 && num <= 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 128; i++)
	{
		if (num == i)
		{
			printf("%c\n", num);
		}
	}
}
