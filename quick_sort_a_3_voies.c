#include "push_swap.h"

int	find_pivot(t_stack *stack)
{
	int pivot;

	pivot = stack_size(stack) / 2;
	return (pivot);
}

void partition_stack(t_stack **a, t_stack **b, int pivot, int fd)
{
	int i;
	int initial_size;

	i = 0;
	initial_size = stack_size(*a);
	while (i < initial_size)
	{
		if ((*a)->id < pivot)
		{
			//printf("plus petit id = %d\n", (*a)->id);
			pb(a, b, fd);
		}
		else
		{
			//printf("plus grand id = %d\n", (*a)->id);
			ra(a, fd);
		}
		i++;
	}
}

void	quick_sort_a_3_voies(t_stack **a, t_stack **b, int lst_size, int fd)
{
	(void)lst_size;
	int pivot;
	int size_b;
	int size_a;
(void)size_a;
	pivot = find_pivot(*a);
	printf("pivot = %d\n", pivot);
	if (pivot == -1)
		ft_exit_error();
	partition_stack(a, b, pivot, fd);
	size_b = stack_size(*b);
	printf("size_b = %d\n", size_b);
	//if (size_b > 1)
      // quick_sort_a_3_voies(b, a, size_b, fd);
	// while (*b != NULL)
    //     pa(a, b, fd);
	//size_a = stack_size(*a);
	//printf("size_a = %d\n", size_a);
	// if (size_a > 1)
	// 	quick_sort_a_3_voies(a, b, lst_size, fd);
}
