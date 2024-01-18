# include "monty.h"

/**
 * handle_pall - function that prints all elements in a stack
 * @stack: node from the dlist stack struct
 * @line_number: line position for opcode
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
