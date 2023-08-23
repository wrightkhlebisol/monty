#include "monty.h"

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
	int MAX_SIZE = 128, lineht = 0;
	char chunk[MAX_SIZE];
	instruction_t opcodes[] = {
		{"push", push},
		{"pop", pop},
/*		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
*/		NULL
	};

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
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
		char *token_s = strtok(chunk, "\t\r\n ");
		int i = 0;

		while (opcodes[i].opcode != NULL )
		{
			if (strcmp(token_s, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(head, lineht);
			}
			i++;
		}

		
		token_s = strtok(NULL, "\t\r\n ");
		printf("%s\n", token_s);
		
		lineht++;
		// Add each line to a stack
	}
	fclose(fp);
	// Pop and interpret
	exit(1);
}
