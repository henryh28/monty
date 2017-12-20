#include "monty.h"


/**
 * op_push     - Push a node on top of a stack
 *
 * @stack:       A doubly linked list
 * @line_number: Current line number in monty script file
 */

void op_push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(global.value);
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}


/**
 * op_pall      - Print all nodes in stack
 *
 * @stack:        A doubly linked list
 * @line_number:  Current line number in monty script file
 */

void op_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		       current = current->next;
	}
}




