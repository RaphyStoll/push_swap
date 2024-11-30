/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:04:31 by raphalme          #+#    #+#             */
/*   Updated: 2024/11/14 15:06:03 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// trie une liste de 2 elements
void	sort_2(t_stack **a)
{
	if (stack_size(*a) != 2)
		return ;
	if ((*a)->id > (*a)->next->id)
		sa(a);
}

// trie une liste de 3 elements
void	sort_3(t_stack **a)
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
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

// trie une liste de 4 elements
void	sort_4(t_stack **a, t_stack **b)
{
	if (stack_size(*a) != 4)
		return ;
	find_smallest(a, b);
	sort_3(a);
	pa(a, b);
}

// trie une liste de 5 elements
void	sort_5(t_stack **a, t_stack **b)
{
	if (stack_size(*a) != 5)
		return ;
	find_biggest(a, b);
	sort_4(a, b);
	pa(a, b);
	ra(a);
}

// switch entre les differents algo selon la taille de la liste
void	small_algo(t_stack **a, t_stack **b, int lst_size)
{
	if (lst_size == 2)
		sort_2(a);
	else if (lst_size == 3)
		sort_3(a);
	else if (lst_size == 4)
		sort_4(a, b);
	else if (lst_size == 5)
		sort_5(a, b);
	return ;
}
