#include "push_swap.h"

int	find_pivot(int lst_size, t_stack *stack)
{
	(void)stack;
	if (lst_size <= 3)
	{
		if (lst_size == 1)
			return (1);
		else if (lst_size == 2)
			return (1);
		else if (lst_size == 3)
			return (2);
	}
		return (lst_size / 2);
}

void partition_stack(t_stack **a, t_stack **b, int pivot, int fd)
{
	printf("partition_stack\n");
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
	pivot = find_pivot(lst_size, *a);
	printf("pivot = %d\n", pivot);
	if (pivot == -1)
		ft_exit_error();
	partition_stack(a, b, pivot, fd);
	size_b = stack_size(*b);
	
		if (lst_size <= 5 && lst_size > 0)
		{
			small_algo(a, b, lst_size, fd);
		}
		else if (size_b > 3)
		{
		printf("size_b = %d\n", size_b);
		printf("quick_sort_b\n");
    	quick_sort_a_3_voies(b, a, size_b, fd);
		}
	// while (*b != NULL)
    //     pa(a, b, fd);
	// size_a = stack_size(*a);
	//printf("size_a = %d\n", size_a);
	//  if (size_a > 2)
	// {
	// 	printf("quick_sort_a\n");
	//  	quick_sort_a_3_voies(a, b, size_a, fd);
	
	// }
}
