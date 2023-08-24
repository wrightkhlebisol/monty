#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head: the pointer to the head node pointer
 * @line_number: the line number
 *
 * Return: void
 */
void swap(stack_t **head, unsigned int line_number)
{
	int tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}

/**
 * nop - swaps the top two elements of the stack
 * @head: the pointer to the head node pointer
 * @line_number: the line number
 *
 * Return: void
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
