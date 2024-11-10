/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:46:46 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/10 16:30:40 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///verification des doublon
int	is_dooble(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	puts("rentre dans isdoublon");
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//verification de la chaine de caracterey
int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] > 2147483647)
		ft_exit_error();
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
	int count = 0; //$

	stack = NULL;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	while(argv[count])
		count++;
	argc = count;
	if (argc < 2)
		return (stack);
	if (is_dooble(argc, argv))
	{
		puts("isdoublon");
		ft_exit_error();
	}
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
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
