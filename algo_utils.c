/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:03:33 by raphalme          #+#    #+#             */
/*   Updated: 2024/11/14 14:30:30 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief
** ne marche que pour les piles de 4
** cherche le plus petit nombre(id = 1) et le push sur la pile b
1*/
void	find_smallest(t_stack **a, t_stack **b)
{
	int	second;
	int	third;
	int	fourth;

	second = (*a)->next->id;
	third = (*a)->next->next->id;
	fourth = set_last(a);
	if ((*a)->id == 0)
		pb(a, b);
	else if (second == 0)
	{
		sa(a);
		pb(a, b);
	}
	else if (third == 0)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (fourth == 0)
	{
		rra(a);
		pb(a, b);
	}
}
/**
 *@brief
 ** ne marche que pour les piles de 5
 ** cherche le plus grand nombre(id = 4) et le push sur la pile b
 2*/

void	find_biggest(t_stack **a, t_stack **b)
{
	if ((*a)->id == 4)
		pb(a, b);
	else if ((*a)->next->id == 4)
	{
		sa(a);
		pb(a, b);
	}
	else if ((*a)->next->next->id == 4)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if ((*a)->next->next->next->id == 4)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if ((*a)->next->next->next->next->id == 4)
	{
		pb(a, b);
	}
}
