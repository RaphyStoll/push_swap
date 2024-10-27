/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:06:00 by raphalme          #+#    #+#             */
/*   Updated: 2024/10/26 17:06:01 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// set le dernier id
int	set_last(t_stack **lst)
{
	t_stack	*current;

	if (*lst == NULL)
	{
		ft_exit_error();
	}
	current = *lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current->id);
}

// set l'avant dernier id
int	set_prev(t_stack **lst)
{
	t_stack	*current;
	int		*value;

	if (*lst == NULL)
	{
		ft_exit_error();
	}
	current = (*lst);
	while (current->next->next != NULL)
	{
		value = &current->next->id;
		current = current->next;
	}
	return (*value);
}

// verifie si la liste est trier
int	is_sorted(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
		{
			return (0);
		}
		stack = stack->next;
	}
	puts("trier par defaut");
	return (1);
}
