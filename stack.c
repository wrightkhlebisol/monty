#include "monty.h"

/**
 * push - Put item at top of stack
 * @head
 * @n
 *
 * Return
 */
int push(stack_t *head, int n)
{
	stack_t *temp = head;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		exit(EXIT_FAILURE);

	new_node->n = n;
	new_node->prev = NULL;

	if (head == NULL)
	{
		new_node->next = NULL;
		head = new_node;
		exit(EXIT_SUCCESS);
	}
	new_node->next = temp;
	temp->prev = new_node;
	head = new_node;
	exit(EXIT_SUCCESS);
}

int pop(stack_t *head)
{
	stack_t *temp = NULL;

	if (head == NULL)
		exit(EXIT_FAILURE);

	temp = head;
	head = temp->next;
	temp->next->prev = NULL;
	temp->next = NULL;
	free(temp);
	exit(EXIT_SUCCESS);
}

int peak(stack_t *head)
{
	if (head == NULL)
		exit(EXIT_FAILURE);

	return (head->n);
}
