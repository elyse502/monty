#include "monty.h"

/**
 * pall - Prints the stack.
 * @stack: Stack given by main in start.c.
 * @line_cnt: Amount of lines.
 *
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}
