#include "push_swap.h"

//trie une liste de 2 elements
void sort_2(t_stack **a, int fd)
{
	if (stack_size(*a) != 2)
		return ;
	if ((*a)->id > (*a)->next->id)
    sa(a, fd);
}

//trie une liste de 3 elements
void sort_3(t_stack **a, int fd)
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

//trie une liste de 4 elements
void	sort_4(t_stack **a, t_stack **b, int fd, int first, int second,
int third, int fourth)
{
	
	if (stack_size(*a) != 4)
		return ;
	find_smallest(a, b, fd, first, second, third, fourth);
	sort_3(a, fd);
	pa(a, b, fd);
}

//trie une liste de 5 elements
void	sort_5(t_stack **a, t_stack **b, int fd, int first, int second,
int third, int fourth, int fifth)
{
	(void)b;
	(void)fd;
	(void)first;
	(void)second;
	(void)third;
	(void)fourth;
	(void)fifth;
	
	if (stack_size(*a) != 5)
		return ;
}

//switch entre les differents algo selon la taille de la liste
void small_algo(t_stack **a, t_stack **b, int lst_size, int fd)
{
	int	first;
	int	second;
	int	third;
	int	fourth;
	int	five;

	first = (*a)->id;
	second = (*a)->next->id;
	third = (*a)->next->next->id;
	fourth = set_prev(a);
	five = set_last(a);

	(void)b;
	if (lst_size == 2)
		sort_2(a, fd);
	else if (lst_size == 3)
		sort_3(a, fd);
	else if (lst_size == 4)
		sort_4(a, b, fd, first, second, third, fourth);
	else if (lst_size == 5)
		sort_5(a, b, fd, first, second, third, fourth, five);
	return ;
}