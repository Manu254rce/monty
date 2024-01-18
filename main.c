# include "monty.h"

/**
 * opcode_handler - function for handling stack opcodes
 * @file: file pointer to stream
 */

void opcode_handler(FILE *file)
{
	char *line = NULL;
	int i;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	instruction_t list[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"nop", handle_nop},
		{NULL, NULL}
	};

	while ((read = getline(&line, &len, file)) != -1)
	{
		line[strcspn(line, "\n")] = 0;
		for (i = 0; list[i].opcode != NULL; ++i)
		{
			if (strcmp(line, list[i].opcode) == 0)
			{
				list[i].f(NULL, line_number);
				break;
			}
		}
		if (list[i].opcode == NULL)
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);

		line_number++;
	}
	free(line);
}

/**
 * main - entry point for our Monty interpreter
 * @argc: command line argument numbers
 * @argv: command line argument vector
 * Return: 0 if Success
 */

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	opcode_handler(file);

	fclose(file);
	return (0);
}
