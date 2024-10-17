#include "push_swap.h"

t_stack	*ft_lstnew(void *value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		if (new == NULL)
			return ;
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*current;
	t_stack	*next;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->value);
		free(current);
		current = next;
	}
	*lst = NULL;
}