#include "monty.h"

/**
 * check_num - checks if argument is a number or not, covers digits as well
 * @num: number argument
 *
 * Return: 1 (number or digit), 0 (not a number nor digit)
 */
int check_num(char *num)
{
	if (*num == '-')
	{
		num++;
	}
	if (*num == '\0')
		return (0);
	while (*num != '\0')
	{
		if (*num < '0' || *num > '9')
			return (0);
		num++;
	}
	return (1);
}

/**
 * push - Put item at top of stack
 * @head
 * @n
 *
 * Return
 */
void push(stack_t **head, unsigned int line_number)
{
	int num;
	char *cmd_arg;
/**
	printf("%p\n", &head);
*/
	if (head == NULL)
	{
		fprintf(stderr, "Stack is not present\n");
		exit(EXIT_FAILURE);
	}

	cmd_arg = strtok(NULL, "\t\n ");
/**
	printf("%s\n", cmd_arg);
*/
	if (cmd_arg == NULL || check_num(cmd_arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(*head);
		exit(EXIT_FAILURE);
	}

	num = atoi(cmd_arg);
	
	stack_t *temp = *head;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
	{
		temp->prev = new_node;
	}
	*head = new_node;
}

void pall(stack_t **head, __attribute__((unused)) unsigned int line_number)
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
