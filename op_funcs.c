#include "monty.h"

/**
 * push - push to plate
 *
 * @stack: reference stack
 * @line_number: monty line number
 */
void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new;
	stack_t *temp;

	temp = *stack;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(global.value);
	new->prev = NULL;

	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
		exit(EXIT_FAILURE);
	}

	new->next = *stack;
	temp->prev = new;

	*stack = new;
}

/**
 * pop - remove top plate
 *
 * @stack: reference stack
 * @line_number: monty line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *position;

	if (stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	position = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(position);
}

/**
 * nop - does nothing
 *
 * @stack: reference stack
 * @line_number: monty line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap - swap two plates
 *
 * @stack: reference stack
 * @line_number: monty line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = (*stack)->n - (*stack)->next->n;
	(*stack)->n = (*stack)->n - (*stack)->next->n;
}

/**
 * add - add two plates
 *
 * @stack: reference stack
 * @line_number: monty line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *position;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	position = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;

	free(position);
}
