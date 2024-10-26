/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:38:59 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/26 00:52:08 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push le premier element de src sur dest
void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	return ;
}

void	pb(t_stack **a, t_stack **b, int fd)
{
	push(a, b);
	ft_putstr_fd("pb\n", fd);
	return ;
}

void	pa(t_stack **a, t_stack **b, int fd)
{
	push(b, a);
	ft_putstr_fd("pa\n", fd);
	return ;
}
