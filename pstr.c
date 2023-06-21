#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pstr - Prints the contents of a stack_t stack as a string.
 * @stack: Stack given by main.
 * @line_cnt: Line counter for error messages
 *
 * Return: Nothing.
 */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}


