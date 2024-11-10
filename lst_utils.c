/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:40:45 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/09 15:07:04 by raphalme         ###   ########.fr       */
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
void	print_node(t_stack *current)
{
	ft_putnbr(current->value);
	ft_putstr_fd("(", 1);
	ft_putnbr(current->id);
	ft_putstr_fd(") -> ", 1);
}

//print la liste
void	print_list(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current != NULL)
	{
		print_node(current);
		current = current->next;
	}
	ft_putstr_fd("NULL\n", 1);
	return ;
}
