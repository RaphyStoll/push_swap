#include "push_swap.h"

//verification de la chaine de caractere
int ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

//creation de la pile depuis argv
t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = argc - 1;
	if (argc > 2)
		ft_exit_error();
	while (i > 0)
	{
		if (!ft_isnumber(argv[i]))
			ft_exit_error();
		push(&stack, ft_atoi(argv[i]));
	}
	return (stack);
}

//ajoute un element au sommet de la pile
void push(t_stack **stack, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_exit_error();
	new->value = value;
	new->next = *stack;
	*stack = new;
}

//retire et retourne l'element au sommet de la pile
int pop(t_stack **stack)
{
	t_stack	*tmp;
	int		value;

	if (!*stack)
		ft_exit_error();
	tmp = *stack;
	value = tmp->value;
	*stack = tmp->next;
	free(tmp);
	return (value);
}

//affiche la pile
