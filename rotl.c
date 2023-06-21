#include "monty.h"

/**
* rotl - Rotates the first element of the stack.
* @stack: Stack head.
* @line_count: Line count.
*
* Return: void.
*/
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *left;
	stack_t *right;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left = right = *stack;

	while (right->next) /* Move the right pointer to the last node */
		right = right->next;
	right->next = left; /* A circle infinite linked list loop */
	left->prev = right;
	*stack = left->next; /* So we cut the link between the 0 and 1 element */
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


