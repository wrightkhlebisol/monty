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

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
