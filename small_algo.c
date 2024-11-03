/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:04:31 by raphalme          #+#    #+#             */
/*   Updated: 2024/11/03 12:05:02 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// trie une liste de 2 elements
void	sort_2(t_stack **a, int fd)
{
	puts("sort_2");
	if (stack_size(*a) != 2)
		return ;
	if ((*a)->id > (*a)->next->id)
		sa(a, fd);
}

// trie une liste de 3 elements
void	sort_3(t_stack **a, int fd)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->id;
	second = (*a)->next->id;
	third = (*a)->next->next->id;
	if (stack_size(*a) != 3)
		return ;
	if (first > second && second < third && first < third)
		sa(a, fd);
	else if (first > second && second > third)
	{
		sa(a, fd);
		rra(a, fd);
	}
	else if (first > second && second < third && first > third)
		ra(a, fd);
	else if (first < second && second > third && first < third)
	{
		sa(a, fd);
		ra(a, fd);
	}
	else if (first < second && second > third && first > third)
		rra(a, fd);
}

// trie une liste de 4 elements
void	sort_4(t_stack **a, t_stack **b, int fd)
{
	if (stack_size(*a) != 4)
		return ;
	find_smallest(a, b, fd);
	sort_3(a, fd);
	pa(a, b, fd);
}

// trie une liste de 5 elements
void	sort_5(t_stack **a, t_stack **b, int fd)
{
	if (stack_size(*a) != 5)
		return ;
	find_biggest(a, b, fd);
	sort_4(a, b, fd);
	pa(a, b, fd);
	ra(a, fd);
}

// switch entre les differents algo selon la taille de la liste
void	small_algo(t_stack **a, t_stack **b, int lst_size, int fd)
{
	if (lst_size == 2)
		sort_2(a, fd);
	else if (lst_size == 3)
	{
		// puts("sort3");
		sort_3(a, fd);
	}
	else if (lst_size == 4)
		sort_4(a, b, fd);
	else if (lst_size == 5)
		sort_5(a, b, fd);
	return ;
}
