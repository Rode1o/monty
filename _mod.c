#include "monty.h"

/**
 *
 *
 *
 *
 *
 *
 *
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *delete = NULL;
	int mod = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		frees(*stack);
		exit(2);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		frees(*stack);
		exit(2);
	}

	mod = (*stack)->next->n % (*stack)->n;

	delete = *stack;
	*stack = (*stack)->next;

	(*stack)->n = mod;
	(*stack)->prev = NULL;

	delete->next = NULL;
	free(delete);
}
