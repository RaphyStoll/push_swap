/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:44:52 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/05 22:12:49 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// tri a bulle pour les id (si pas assez rapide le changer)
// tri a bulle pour les id (si pas assez rapide le changer)

// void	bubble_sort(int *tab, int size)
// {
// 	int		i;
// 	int		j;
// 	int	temp;
// 	int		swapped;

// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		j = 0;
// 		swapped = 0;
// 		while (j < size - i - 1)
// 		{
// 			if (tab[j] > tab[j + 1])
// 			{
// 				temp = tab[j];
// 				tab[j] = tab[j + 1];
// 				tab[j + 1] = temp;
// 				swapped = 1;
// 			}
// 			j++;
// 		}
// 		if (swapped == 0)
// 			break ;
// 		i++;
// 	}
// }
// // assigne les id a chaque valeur dans la liste
// // ces id sont les valeurs trier
// void	assign_indices(t_stack *a, int size)
// {
// 	int	*tab;
// 	int		i;
// 	int		j;
// 	t_stack	*current;

// 	tab = malloc(sizeof(int) * size);
// 	if (!tab)
// 		ft_exit_error();
// 	current = a;
// 	i = 0;
// 	while (i < size)
// 	{
// 		tab[i] = current->value;
// 		current = current->next;
// 		i++;
// 	}
// 	bubble_sort(tab, size);
// 	current = a;
// 	while (current)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (current->value == tab[j])
// 			{
// 				current->id = j;
// 				break ;
// 			}
// 			j++;
// 		}
// 		current = current->next;
// 	}
// 	free(tab);
// }


// Fonction de partitionnement pour Quick Sort
int	partition_func(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			// Échange arr[i] et arr[j]
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	// Échange arr[i + 1] et arr[high] (le pivot)
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

// Fonction Quick Sort
void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition_func(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

// Fonction pour assigner les IDs basés sur les valeurs triées (0 à n-1)
void	assign_indices(t_stack *a, int size)
{
	int	*tab;
	int	i;
	int	j;
	t_stack	*current;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		ft_exit_error();
	// Copier les valeurs dans le tableau
	current = a;
	for (i = 0; i < size; i++)
	{
		tab[i] = current->value;
		current = current->next;
	}
	// Trier le tableau avec Quick Sort
	quick_sort(tab, 0, size - 1);
	// Assigner les IDs de 0 à n-1
	current = a;
	while (current != NULL)
	{
		j = 0;
		while (j < size)
		{
			if (current->value == tab[j])
			{
				current->id = j; // Assignation de 0 à n-1
				break ;
			}
			j++;
		}
		current = current->next;
	}
	// Libérer la mémoire allouée au tableau
	free(tab);
}
