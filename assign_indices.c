/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:38:36 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/14 14:40:05 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonction pour copier les valeurs de la pile dans un tableau
int	*copy_stack_to_array(t_stack *a, int size)
{
	int		*arr;
	int		i;
	t_stack	*current;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		ft_exit_error();
	current = a;
	i = 0;
	while (current)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	return (arr);
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

// Fonction pour assigner les indices basés sur les valeurs triées
void	assign_indices(t_stack *a, int size)
{
	int		*sorted_arr;
	int		i;
	t_stack	*current;

	sorted_arr = copy_stack_to_array(a, size);
	quick_sort(sorted_arr, 0, size - 1);
	current = a;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted_arr[i])
			{
				current->id = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(sorted_arr);
}

// Fonction de partition pour Quick Sort
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
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}
