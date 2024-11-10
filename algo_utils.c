/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:03:33 by raphalme          #+#    #+#             */
/*   Updated: 2024/11/09 15:14:11 by raphalme         ###   ########.fr       */
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
	if ((*a)->id == 1)
		pb(a, b);
	else if (second == 1)
	{
		sa(a);
		pb(a, b);
	}
	else if (third == 1)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (fourth == 1)
	{
		rra(a);
		pb(a, b);
	}
}
/**
 *@brief
 ** ne marche que pour les piles de 5
 **
 *@param
 *? toutes les valeur 1 par ligne
 2*/

void	find_biggest(t_stack **a, t_stack **b)
{
	if ((*a)->id == 5)
		pb(a, b);
	else if ((*a)->next->id == 5)
	{
		sa(a);
		pb(a, b);
	}
	else if ((*a)->next->next->id == 5)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if ((*a)->next->next->next->id == 5)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if ((*a)->next->next->next->next->id == 5)
	{
		rra(a);
		pb(a, b);
	}
}
