/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonne_chance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:03:40 by raphalme          #+#    #+#             */
/*   Updated: 2024/11/01 17:55:41 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(t_stack *a, int lst_size)
{
	int		pivot;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	while (i < lst_size / 2)
	{
		tmp = tmp->next;
		i++;
	}
	pivot = tmp->id;
	return (pivot);
}

void	partition_stack_by_pivot(t_stack **a, t_stack **b, int pivot, int fd)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->id < pivot)
			pb(a, b, fd);
		else if (tmp->id == pivot)
			ra(a, fd);
		else if (tmp->id > pivot)
			ra(a, fd);
		tmp = tmp->next;
	}
}

void	medium_algo(t_stack **a, t_stack **b, int lst_size, int fd)
{
	int	pivot;

	pivot = find_pivot(*a, lst_size);
	partition_stack_by_pivot(a, b, pivot, fd);
}
