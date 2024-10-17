#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack {
	int value;
	struct s_stack *next;
} t_stack;

// d'operations sur la pile
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// utils
void	ft_putstr(char *s);