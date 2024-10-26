/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:46:46 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/26 01:27:18 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//verification de la chaine de caracterey
int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

//creation de la pile depuis argv
t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int	value;

	stack = NULL;
	if (argc < 2)
		return (stack);
	i = argc - 1;
	while (i > 0)
	{
		if (!ft_isnumber(argv[i]))
			ft_exit_error();
		value = ft_atoi(argv[i]);
		ft_lstadd_front(&stack, ft_create_node(value));
		i--;
	}
	return (stack);
}

// Fonction pour calculer la taille de la pile
int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
