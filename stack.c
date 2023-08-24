#include "monty.h"
/**
 * push - Put item at top of stack
 * @head
 * @n
 *
 * Return
 */
void push(stack_t **head, unsigned int line_number)
{
	if (token_s == NULL || !isdigit(*token_s))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	int num = atoi(token_s);
	
	stack_t *temp = *head;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;

	if (head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		exit(EXIT_SUCCESS);
	}
	new_node->next = temp;
	temp->prev = new_node;
	*head = new_node;
	exit(EXIT_SUCCESS);
}

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
void pop(void)
{
	stack_t *temp = NULL;

	if (head == NULL)
		exit(EXIT_FAILURE);

	temp = *head;
	*head = temp->next;
	temp->next->prev = NULL;
	temp->next = NULL;
	free(temp);
	exit(EXIT_SUCCESS);
}

void peak(void)
{
	if (head == NULL)
		exit(EXIT_FAILURE);

	printf("%d\n", (*head)->n);
}
*/
