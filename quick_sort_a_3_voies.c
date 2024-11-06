#include "push_swap.h"

int	find_pivot(int lst_size, t_stack *a)
{
	int	*pivot_arr;
	int	median;
	int	i;

	pivot_arr = malloc(sizeof(int) * lst_size);
	if (!pivot_arr)
		ft_exit_error();

	// Copier les IDs dans un tableau
	i = 0;
	t_stack *current = a;
	while (current != NULL && i < lst_size)
	{
		pivot_arr[i] = current->id;
		current = current->next;
		i++;
	}

	// Trier le tableau des IDs pour trouver la médiane
	quick_sort(pivot_arr, 0, lst_size - 1);

	// La médiane est l'élément au centre
	median = pivot_arr[lst_size / 2];
	free(pivot_arr);
	return (median);
}

void partition_stack_a(t_stack **a, t_stack **b, int pivot, int fd)
{
	printf("partition_stack_a\n");
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

void partition_stack_b(t_stack **a, t_stack **b, int pivot, int fd)
{
	printf("partition_stack_b\n");
	int i;
	int initial_size;

	i = 0;
	initial_size = stack_size(*a);
	while (i < initial_size)
	{
		if ((*b)->id < pivot)
		{
			//printf("plus petit id = %d\n", (*a)->id);
			pa(a, b, fd);
		}
		else
		{
			//printf("plus grand id = %d\n", (*a)->id);
			rb(b, fd);
		}
		i++;
	}
}

void quick_sort_a_3_voies(t_stack **a, t_stack **b, int lst_size, int fd)
{
    printf("\n===quick_sort_a_3_voies===\n");
    print_list(a, fd);
    print_list(b, fd);

    int pivot;
    int size_b;
    int size_a;

    printf("lst_size = %d\n", lst_size);

    // Cas de base pour les petites piles (<= 5 éléments)
    if (lst_size <= 5)
    {
        printf("--->inf a 5<-----\n");
        small_algo(a, b, lst_size, fd);
        print_list(a, fd);
        print_list(b, fd);
        return;
    }

    // Trouver le pivot et partitionner
    pivot = find_pivot(lst_size, *a);
    printf("pivot = %d\n", pivot);
    if (pivot == -1)
        ft_exit_error();
    
    partition_stack_a(a, b, pivot, fd);

    // Récupérer les nouvelles tailles après partitionnement
    size_b = stack_size(*b);
    size_a = stack_size(*a);
    printf("size_b = %d\n", size_b);
    printf("size_a = %d\n", size_a);

    // Appels récursifs pour trier les sous-piles
    if (size_a > 1)
	{
		puts("recursive a");
        quick_sort_a_3_voies(a, b, size_a, fd);
	}
	if (size_b > 1)
    {
		puts("recursive b");
	    quick_sort_a_3_voies(b, a, size_b, fd);
	}
    // Réintégrer les éléments de b dans a
    while (*b != NULL)
        pa(a, b, fd);
}
