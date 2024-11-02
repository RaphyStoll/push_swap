#include "push_swap.h"

/**
*@brief
** cherche le plus petit nombre(id = 1) et le push sur la pile b
*@param f = first, s = second, t = third, fo = fourth
1*/
void find_smallest(t_stack **a, t_stack **b, int fd, int f, int s, int t, int fo)
{
	if (f == 1)
	 pb(a, b, fd);
	else if(s == 1)
	{
		sa(a, fd);
		pb(a, b, fd);
	}
	else if (t == 1)
	{
		ra(a, fd);
		ra(a, fd);
		pb(a, b, fd);
	}
	else if (fo == 1)
	{
		rra(a, fd);
		pb(a, b, fd);
	}
}