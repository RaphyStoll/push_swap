/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:48:53 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/03 08:52:02 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction pour mettre le premier element en dernier
void	rotate(t_stack **head)
{
    t_stack	*temp;
    t_stack	*last;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return;
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

void	ra(t_stack **a, int fd)
{
	rotate(a);
	ft_putstr_fd("ra\n", fd);
	return ;
}

void	rb(t_stack **b, int fd)
{
	rotate(b);
	ft_putstr_fd("rb\n", fd);
	return ;
}

void	rr(t_stack **a, t_stack **b, int fd)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", fd);
	return ;
}
