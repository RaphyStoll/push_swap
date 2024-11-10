/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:38:06 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/09 15:13:14 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap les deux premiers elements de la liste
void	swap(t_stack **lst)
{
	int	tmp_value;
	int	tmp_id;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	tmp_value = (*lst)->value;
	tmp_id = (*lst)->id;
	(*lst)->value = (*lst)->next->value;
	(*lst)->id = (*lst)->next->id;
	(*lst)->next->value = tmp_value;
	(*lst)->next->id = tmp_id;
	return ;
}

void	sa(t_stack **a)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

// swap a et b
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
	return ;
}
