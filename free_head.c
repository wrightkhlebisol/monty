#include "monty.h"

/**
 * free_head - frees the stack dynamically allocated memory
 * @head: head node pointer
 *
 * Return: void
 */
void free_head(stack_t *head)
{
	stack_t *temp = NULL;

	while (head)
	{
		temp = head;
		head = temp->next;
		free(temp);
		head = temp;
	}
}
