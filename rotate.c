/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:48:53 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/14 15:05:33 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction pour mettre le premier element en dernier
void	rotate(t_stack **head)
{
	t_stack	*temp;
	t_stack	*last;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	temp->next = NULL;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->prev = last;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
	return ;
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
	return ;
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
	return ;
}
