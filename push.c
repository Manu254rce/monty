# include "monty.h"

/**
 * handle_push - function that handles push operations
 * @stack: node for the dlist struct
 * @line_number: line position for the opcode
 */

void handle_push(stack_t **stack, unsigned int line_number)
{
	int n;
	char *token;
	stack_t *new_node;

	token = strtok(NULL, "\t\n");
	if (token == NULL || !isdigit(token))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(token);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
