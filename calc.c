#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: the pointer to the head node pointer
 * @line_number: the line number
 *
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	pop(head, line_number);
}

/**
 * sub - subtracts the top elements from the second in the stack
 * @head: the pointer to the head node pointer
 * @line_number: the line number
 *
 * Return: void
 */
void sub(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	pop(head, line_number);
}

/**
 * op_div - divides the 2nd top by the top element of the stack
 * @head: the pointer to the head node pointer
 * @line_number: the line number
 *
 * Return: void
 */
void op_div(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n /= (*head)->n;
	pop(head, line_number);
}

/**
 * mul - multiplies the 2nd top by the top element of the stack
 * @head: the pointer to the head node pointer
 * @line_number: the line number
 *
 * Return: void
 */
void mul(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	pop(head, line_number);
}

/**
 * mod - remainder of div of second top elem by top in stack
 * @head: the pointer to the head node pointer
 * @line_number: the line number
 *
 * Return: void
 */
void mod(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n %= (*head)->n;
	pop(head, line_number);
}
