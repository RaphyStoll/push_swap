/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:40:45 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/26 01:28:24 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ajoute un element au debut de la liste
void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		new->prev = NULL;
		if (*lst)
			(*lst)->prev = new;
		*lst = new;
	}
}

//creer un nouveau noeud
t_stack	*ft_create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		ft_exit_error();
	new_node->value = value;
	new_node->id = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

//print un noeud de la liste
void	print_node(t_stack *current, int fd)
{
	ft_putnbr(current->value);
	ft_putstr_fd("(", fd);
	ft_putnbr(current->id);
	ft_putstr_fd(") -> ", fd);
}

//print la liste
void	print_list(t_stack **head, int fd)
{
	t_stack	*current;

	current = *head;
	while (current != NULL)
	{
		print_node(current, fd);
		current = current->next;
	}
	ft_putstr_fd("NULL\n", fd);
	return ;
}
