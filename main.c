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
	int MAX_SIZE = 128;
	char chunk[MAX_SIZE];

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while(fgets(chunk, MAX_SIZE, fp) != NULL)
	{
		char *token_s = strtok(chunk, "\t\r\n ");
		while(token_s)
		{
			printf("%s\n", token_s);
			token_s = strtok(NULL, "\t\r\n ");
		}
		// Add each line to a stack
	}
	fclose(fp);
	// Pop and interpret
	exit(1);
}
