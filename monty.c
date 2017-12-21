#include "monty.h"

global_t global;

/**
 * find_function   - Find function to match argument, if any
 *
 * @stack:           Head of stack data structure
 * @line_number:     Line number of current line in monty file
 */

void find_function(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	instruction_t functions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{NULL, NULL}
	};

	while (functions[i].opcode != NULL)
	{
		if (strcmp(global.op_name, functions[i].opcode) == 0)
		{
			functions[i].f(stack, line_number);
			break;
		}
		i++;
	}
}



/**
 * main     - InterpretsMonty bytecodes
 *
 * @argc:     Number of arguments
 * @argv:     Array of arguments
 *
 * Return:    Success: EXIT_SUCCESS
 *            Failure: EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	stack_t *head = NULL;
	FILE *fp;
	char *line = NULL;
	size_t line_length = 0;
	unsigned int line_number = 1;

	if (argc < 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file <file> %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &line_length, fp) != -1)
	{
		global.op_name = strtok(line, "\n\t ");
		global.value = strtok(NULL, " ");

		find_function(&head, line_number);
		line_number++;
	}

	exit(EXIT_SUCCESS);
}
