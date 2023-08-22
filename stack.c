#include "monty.h"

int push(stack_m *head, int n)
{
	stack_m *temp = head;
	stack_m *new_node = malloc(sizeof(stack_m));
	
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

int pop(stack_m *head)
{
	stack_m *temp = NULL;
	if (head == NULL)
		exit(EXIT_FAILURE);
	
	temp = head;
	head = temp->next;
	temp->next->prev = NULL;
	temp->next = NULL;
	free(temp);
	exit(EXIT_SUCCESS);
}

int peak(stack_m *head)
{
	if (head == NULL)
		exit(EXIT_FAILURE);

	return (head->n);
}
