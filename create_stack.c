/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:46:46 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/14 14:51:28 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///verification des doublon
int	is_dooble(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_exit_error();
			}
			j++;
		}
		i++;
	}
	return (0);
}

//verification de la chaine de caracterey
//* @s = sign si 1 = '+' si -1 = '-'
int	ft_isnumber(char *str)
{
	int		i;
	long	result;
	int		s;	

	i = 0;
	result = 0;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		if ((s == 1 && result > INT_MAX) || (s == -1 && - result < INT_MIN))
			ft_exit_error();
		i++;
	}
	return (1);
}

//cree le nouveau argv apres le split de la chaine
//en gardant argv[1] = ./programme_name
char	**new_av(char **argv)
{
	char	**tab;
	int		count;
	int		index;

	index = 1;
	count = 0;
	tab = ft_split(argv[1], ' ');
	while (tab[count] != NULL)
	{
		argv[index] = tab[count];
		count++;
		index++;
	}
	argv[index] = NULL;
	return (argv);
}

//creation de la pile depuis argv
t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		value;

	stack = NULL;
	if (argc == 2)
		argv = new_av(argv);
	argc = set_argc(argc, argv);
	if (argc < 2)
		return (stack);
	is_dooble(argc, argv);
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

int	set_argc(int argc, char **argv)
{
	int	count;

	count = 0;
	while (argv[count])
		count++;
	argc = count;
	return (argc);
}
