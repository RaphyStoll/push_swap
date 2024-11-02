/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:44:52 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/26 01:31:26 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// tri a bulle pour les id (si pas assez rapide le changer)
void	bubble_sort(int *tab, int size)
{
	int		i;
	int		j;
	int	temp;
	int		swapped;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		swapped = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}
// assigne les id a chaque valeur dans la liste
// ces id sont les valeurs trier
void	assign_indices(t_stack *a, int size)
{
	int	*tab;
	int		i;
	int		j;
	t_stack	*current;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		ft_exit_error();
	current = a;
	i = 0;
	while (i < size)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
	bubble_sort(tab, size);
	current = a;
	while (current)
	{
		j = 0;
		while (j < size)
		{
			if (current->value == tab[j])
			{
				current->id = j + 1;
				break ;
			}
			j++;
		}
		current = current->next;
	}
	free(tab);
}
