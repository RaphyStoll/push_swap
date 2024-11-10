#include "push_swap.h"

// Fonction pour trouver le pivot (médiane des IDs)
int	find_pivot(int lst_size, t_stack *a)
{
	int		*pivot_arr;
	int		median;
	int		i;
	t_stack	*current;

	pivot_arr = malloc(sizeof(int) * lst_size);
	if (!pivot_arr)
		ft_exit_error();
	i = 0;
	current = a;
	while (current != NULL && i < lst_size)
	{
		pivot_arr[i] = current->id;
		current = current->next;
		i++;
	}
	quick_sort(pivot_arr, 0, lst_size - 1);
	median = pivot_arr[lst_size / 2];
	free(pivot_arr);
	return (median);
}

void partition_stack_a(t_stack **a, t_stack **b, int pivot, int i_size)
{
	int	i;

	i = 0;
	while (i < i_size)
	{
		if ((*a)->id < pivot)
		{
			// printf("plus petit id = %d\n", (*a)->id);//$
			pb(a, b);
		}
		else
		{
			// printf("plus grand id = %d\n", (*a)->id);//$
			ra(a);
		}
		i++;
	}
}

void	partition_stack_b(t_stack **a, t_stack **b, int pivot, int i_size)
{
	int	i;

	i = 0;
	while (i < i_size)
	{
		if ((*b)->id >= pivot)
		{
			// printf("plus grand id = %d\n", (*b)->id);//$
			pa(a, b);
		}
		else
		{
			// printf("plus petit id = %d\n", (*b)->id);//$
			rb(b);
		}
		i++;
	}
}

// Fonction de partitionnement
void	partition_stack(t_stack **a, t_stack **b, int pivot,  char w)
{
	int	initial_size;

	//printf("partition_stack\n");//$
	initial_size = stack_size(*a);
	if ( w == 'a')
		partition_stack_a(a, b, pivot, initial_size);
	else
		partition_stack_b(a, b, pivot, initial_size);
}

// Fonction récursive Quick Sort adapté à push_swap
void	q_sort(t_stack **a, t_stack **b, int lst_size, char w)
{
	int	pivot;
	int	size_b;
	int	size_a;

	//printf("\n===quick_sort_a_3_voies===\n");
	//print_list(a); //$ print list
	//print_list(b); //$ print list
	//printf("lst_size = %d\n", lst_size); //$
	// Trouver le pivot et partitionner
	
	if (w == 'a')
		pivot = find_pivot(lst_size, *a);
	else
	pivot = find_pivot(lst_size, w);
	//printf("pivot = %d\n", pivot); //$
	if (pivot == -1)
		ft_exit_error();
	partition_stack(a, b, pivot, w);
	// Récupérer les nouvelles tailles après partitionnement
	size_b = stack_size(*b);
	size_a = stack_size(*a);
	//printf("size_b = %d\n", size_b);//$
	//printf("size_a = %d\n", size_a);//$
	// Debug
	if (size_a == lst_size || size_b == lst_size)
	{
		//printf("Erreur: la partition n'a pas changé la taille des piles\n");//$
		return ;
	}
	// Appels récursifs pour trier les sous-piles
	if (size_a > 1)
	{
		//puts("recursive a");//$
		//print_list(a); //$ print list
		//print_list(b); //$ print list
		q_sort(a, b, size_a, 'a');
	}
	while (size_b-- > 0)
		pa(a, b);
	if (size_b > 1)
	{
		//puts("recursive b");
		//print_list(a); //$ print list
		//print_list(b); //$ print list
		q_sort(b, a, size_b, 'b'); // Ne pas échanger a et b
	}
	//printf("===fin quick_sort_a_3_voies===\n");//$
	// Réintégrer les éléments de b dans a
		
	//printf("===vrais fin quick_sort_a_3_voies===\n");//$
}
