/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:03:33 by raphalme          #+#    #+#             */
/*   Updated: 2024/10/26 17:03:34 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief
** ne marche que pour les piles de 4
** cherche le plus petit nombre(id = 1) et le push sur la pile b
1*/
void	find_smallest4(t_stack **a, t_stack **b, int fd)
{
	int	second;
	int	third;
	int	fourth;

	second = (*a)->next->id;
	third = (*a)->next->next->id;
	fourth = set_last(a);
	if ((*a)->id == 1)
		pb(a, b, fd);
	else if (second == 1)
	{
		sa(a, fd);
		pb(a, b, fd);
	}
	else if (third == 1)
	{
		ra(a, fd);
		ra(a, fd);
		pb(a, b, fd);
	}
	else if (fourth == 1)
	{
		rra(a, fd);
		pb(a, b, fd);
	}
}
/**
 *@brief
 ** ne marche que pour les piles de 5
 **
 *@param
 *? toutes les valeur 1 par ligne
 2*/

void	find_biggest5(t_stack **a, t_stack **b, int fd)
{
	if ((*a)->id == 5)
		pb(a, b, fd);
	else if ((*a)->next->id == 5)
	{
		sa(a, fd);
		pb(a, b, fd);
	}
	else if ((*a)->next->next->id == 5)
	{
		ra(a, fd);
		ra(a, fd);
		pb(a, b, fd);
	}
	else if ((*a)->next->next->next->id == 5)
	{
		rra(a, fd);
		rra(a, fd);
		pb(a, b, fd);
	}
	else if ((*a)->next->next->next->next->id == 5)
	{
		rra(a, fd);
		pb(a, b, fd);
	}
}
