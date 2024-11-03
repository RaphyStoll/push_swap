/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:39:29 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/03 08:52:18 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction pour mettre le dernier element en premier
void	reverse_rotate(t_stack **head)
{
	  t_stack	*prev;
    t_stack	*last;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return ;
    prev = NULL;
    last = *head;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    if (prev != NULL)
        prev->next = NULL;
    last->prev = NULL;
    last->next = *head;
    (*head)->prev = last;
    *head = last;
}

void	rra(t_stack **a, int fd)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", fd);
	return ;
}

void	rrb(t_stack **b, int fd)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", fd);
	return ;
}

void	rrr(t_stack **a, t_stack **b, int fd)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", fd);
	return ;
}
