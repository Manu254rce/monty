# include "monty.h"

/**
 * handle_pall - function that prints all elements in a stack
 * @stack: node of the stack
 * @line_number: the line number on the file being executed
 */

void handle_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pall an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
