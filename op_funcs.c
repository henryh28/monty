#include "monty.h"

/**
 * push - push element
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
