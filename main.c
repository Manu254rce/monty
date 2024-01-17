# include "monty.h"

/**
 * main - entry point for our Monty interpreter implementation
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0 on Success
 */

int main(int argc, char *argv[])
{
	int count;

	

	for (count = 0; count < argc; ++count)
	{
		printf(argv[count]);
		printf("\n");
	}

	return 0;
}
