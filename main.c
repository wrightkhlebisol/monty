#include "monty.h"

stack_t *head = NULL;

/**
 * exec_opcode - finds the opcode that matches with the instruction and executes the function
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
	int MAX_SIZE = 1024;
	char chunk[MAX_SIZE];
	unsigned int line_num = 1;

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

	while(fgets(chunk, MAX_SIZE, fp) != NULL)
	{
		char *token_s = strtok(chunk, "\t\n ");
		if (token_s == NULL)
		{
			line_num++;
			continue;
		}
/**
		printf("%s\n", token_s);
*/
		exec_opcode(token_s, &head, line_num);
		line_num++;
	}
	fclose(fp);
	return (0);
}
