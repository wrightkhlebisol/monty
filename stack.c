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
 * @head: pointer to the head node pointer
 * @line_number: the line number read
 *
 * Return
 */
void push(stack_t **head, unsigned int line_number)
{
	int num;
	char *cmd_arg;
	stack_t *temp = *head;
	stack_t *new_node = malloc(sizeof(stack_t));


	if (head == NULL)
	{
		fprintf(stderr, "Stack is not present\n");
		exit(EXIT_FAILURE);
	}

	cmd_arg = strtok(NULL, " \t\r\n");

	if (cmd_arg == NULL || check_num(cmd_arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(cmd_arg);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		temp->prev = new_node;
	*head = new_node;

}

/**
 * pall - prints all elements present in the stack
 * @head: pointer to the head node pointer
 * @line_number: line number read
 *
 * Return: void
 */
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
 * pop - remove element from the top of the stack
 * @head: pointer to head node pointer
 * @line_number: the line number read
 *
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = temp->next;
	temp->prev = NULL;
	temp->next = NULL;
	free(temp);
}

/**
 * pint - prints element at the top of the stack
 * @head: pointer to head node pointer
 * @line_number: the line number read
 *
 * Return: void
 */
void pint(stack_t **head, unsigned int line_number)
{

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
