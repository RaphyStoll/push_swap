#include "push_swap.h"

//swap le 1er et le second element d'une pile
static void swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

