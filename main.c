#include "monty.h"

/**
 * exec_opcode - finds opcode that matches with command
 * @cmd: the command para
 * @head: head pointer
 * @line_number: number of lines read/executed
 *
 * Return: void
 */
void exec_opcode(char *cmd, stack_t **head, unsigned int line_number)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"div", op_div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	if (*cmd == '#')
	{
		return;
	}

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, cmd) == 0)
		{
			opcodes[i].f(head, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	exit(EXIT_FAILURE);
}

/**
 * main - Start the program
 * @argc: Argument count
 * @argv: Argument Value(s)
 *
 * Return: Error or success code
 */
int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char chunk[MAX_SIZE];
	unsigned int line_num = 1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(chunk, MAX_SIZE, fp) != NULL)
	{
		char *token_s = strtok(chunk, "\t\r\n ");

		if (token_s == NULL)
		{
			line_num++;
			continue;
		}
/*		printf("%s\n", token_s); */
		exec_opcode(token_s, &head, line_num);
		line_num++;
	}
	free_head(head);
	fclose(fp);
	return (0);
}
