#include "push_swap.h"

int	find_pivot(t_stack *a, int lst_size)
{
	int		pivot;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	while (i < lst_size / 2)
	{
		tmp = tmp->next;
		i++;
	}
	pivot = tmp->id;
	return (pivot);
}

void partition_stack(t_stack **a, t_stack **b, int pivot, int fd)
{
	t_stack *current;

	current = *a;
	while (current != NULL)
	{
		if (current->id < pivot)
		{
			puts("plus petit");
			pb(a, b, fd);
		}
		else if (current->id == pivot)
		{
			puts("egal");
			ra(a, fd);
		}
		else if (current->id > pivot)
		{
			puts("plus grand");
			ra(a, fd);
		}
		current = current->next;
	}
}

void	quick_sort_a_3_voies(t_stack **a, t_stack **b, int lst_size, int fd)
{
	int pivot;

	pivot = find_pivot(lst_size);
	printf("pivot: %d\n", pivot);
	if (pivot == -1)
		puts("Error: pivot not found");
	partition_stack(a, b, pivot, fd);
}