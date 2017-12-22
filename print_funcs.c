#include "monty.h"

/**
 * pall - print all values
 *
 * @stack: reference stack
 * @line_number: monty line number
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
  stack_t *position;

  position = *stack;

  if (position == NULL)
    exit(EXIT_FAILURE);

  while (position != NULL)
    {
      printf("%d\n", position->n);
      position = position->next;
    }
}

/**
 * pint - prints top stack value
 *
 * @stack: reference stack
 * @line_number: monty line number
 */
void pint(stack_t **stack, unsigned int line_number)
{ 
  if (*stack == NULL)
    {
      printf("L<%u>: can't pint, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }

  while (*stack != NULL)
    printf("%d\n", (*stack)->n);
}
