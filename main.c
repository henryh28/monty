#include "monty.h"

global_t global;

/**
 * get_op_func - find function
 *
 * @stack: reference stack
 * @line_number: monty line number
 * Return: pointer to function of corresponding operator
 */
void get_op_func(stack_t **stack, unsigned int line_number)
{
  instruction_t ops[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {NULL, NULL}
  };

  int i;

  i = 0;

  while (ops[i].opcode != NULL)
    {
      if (strcmp(global.name, ops[i].opcode) == 0)
	ops[i].f(stack, line_number);
    }     
  i++;
}

void main()
{
  stack_t *head;
  FILE *filename;
  char *line;
  size_t line_length;
  unsigned int line_number;

  head = NULL;
  line = NULL;
  line_length = 0;
  line_number = 0;

  while (getline(&line, &line_length, filename) != -1)
    {
      global.name = strtok(line, "\n\t ");
      global.value = strtok(NULL, " ");

      if (global.name != NULL)
	get_op_func(&head, line_number);
      line_number++;
    }
  exit(EXIT_SUCCESS);
}
