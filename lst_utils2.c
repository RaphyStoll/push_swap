/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:55:20 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/14 14:55:35 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//set le dernier id
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

//set l'avant dernier id
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

//verifie si la liste est trier
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
	return (1);
}

// Fonction pour libérer la pile
void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

// Fonction pour calculer la taille de la pile
int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
