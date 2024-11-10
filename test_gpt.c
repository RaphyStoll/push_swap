#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h> // Pour INT32_MAX

// Structure définie
typedef struct s_stack
{
	int				value;
	int				id;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Fonction pour afficher les opérations
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

// Fonction pour afficher la liste
void	print_list(t_stack **stack, int fd)
{
	t_stack	*current;

	current = *stack;
	while (current != NULL)
	{
		printf("%d(%d) -> ", current->value, current->id);
		current = current->next;
	}
	printf("NULL\n");
}

// Fonction pour calculer la taille de la pile
int	stack_size(t_stack *a)
{
	int	size;

	size = 0;
	while (a != NULL)
	{
		size++;
		a = a->next;
	}
	return (size);
}

// Fonction pour quitter en cas d'erreur
void	ft_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

// Fonction pour créer et ajouter un élément en haut de la pile
void	push_element(t_stack **a, int value, int id)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		ft_exit_error();
	new_node->value = value;
	new_node->id = id;
	new_node->next = *a;
	new_node->prev = NULL;
	if (*a != NULL)
		(*a)->prev = new_node;
	*a = new_node;
}

// Fonction push conforme à la Norme 42
void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	temp->next = *dest;
	temp->prev = NULL;
	if (*dest != NULL)
		(*dest)->prev = temp;
	*dest = temp;
}

// Fonction pa
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

// Fonction pb
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}

// Fonction rotate conforme à la Norme 42
void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
}

// Fonction ra
void	ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

// Fonction rb
void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

// Fonction pour vérifier si la pile est triée
int	is_sorted(t_stack *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->id > a->next->id)
			return (0);
		a = a->next;
	}
	return (1);
}

// Fonction de partitionnement pour Quick Sort
int	partition_func(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			// Échange arr[i] et arr[j]
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	// Échange arr[i + 1] et arr[high] (le pivot)
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

// Fonction Quick Sort
void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition_func(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

// Fonction pour assigner les IDs basés sur les valeurs triées (0 à n-1)
void	assign_indices(t_stack *a, int size)
{
	int	*tab;
	int	i;
	int	j;
	t_stack	*current;

	tab = malloc(sizeof(int) * size);
	if (!tab)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	// Copier les valeurs dans le tableau
	current = a;
	for (i = 0; i < size; i++)
	{
		tab[i] = current->value;
		current = current->next;
	}
	// Trier le tableau avec Quick Sort
	quick_sort(tab, 0, size - 1);
	// Assigner les IDs de 0 à n-1 en gérant les duplications
	current = a;
	while (current != NULL)
	{
		j = 0;
		while (j < size)
		{
			if (current->value == tab[j])
			{
				current->id = j;
				tab[j] = INT32_MAX; // Marquer cette position comme assignée
				break ;
			}
			j++;
		}
		current = current->next;
	}
	// Libérer la mémoire allouée au tableau
	free(tab);
}

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

// Fonction de partitionnement pour la pile 'a'
void	partition_stack_a(t_stack **a, t_stack **b, int pivot, int i_size)
{
	int	i;

	i = 0;
	while (i < i_size)
	{
		if ((*a)->id < pivot)
		{
			// printf("plus petit id = %d\n", (*a)->id);
			pb(a, b);
		}
		else
		{
			// printf("plus grand id = %d\n", (*a)->id);
			ra(a);
		}
		i++;
	}
}

// Fonction de partitionnement pour la pile 'b'
void	partition_stack_b(t_stack **a, t_stack **b, int pivot, int i_size)
{
	int	i;

	i = 0;
	while (i < i_size)
	{
		if ((*b)->id >= pivot)
		{
			// printf("plus grand id = %d\n", (*b)->id);
			pa(a, b);
		}
		else
		{
			// printf("plus petit id = %d\n", (*b)->id);
			rb(b);
		}
		i++;
	}
}

// Fonction de partitionnement générique
void	partition_stack(t_stack **a, t_stack **b, int pivot, char w)
{
	int	initial_size;

	printf("partition_stack\n");
	initial_size = stack_size(*a);
	if (w == 'a')
		partition_stack_a(a, b, pivot, initial_size);
	else
		partition_stack_b(a, b, pivot, initial_size);
}

// Fonction pour libérer la mémoire allouée aux piles
void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

// Fonction récursive Quick Sort adapté à push_swap
void	q_sort(t_stack **a, t_stack **b, int lst_size, char w)
{
	int	pivot;
	int	size_b;
	int	size_a;

	printf("\n===quick_sort_a_3_voies===\n");
	print_list(a, 1);
	print_list(b, 1);
	printf("lst_size = %d\n", lst_size);
	// Trouver le pivot et partitionner
	pivot = find_pivot(lst_size, *a);
	printf("pivot = %d\n", pivot);
	if (pivot == -1)
		ft_exit_error();
	// Ne pas réinitialiser 'w'
	partition_stack(a, b, pivot, w);
	// Récupérer les nouvelles tailles après partitionnement
	size_b = stack_size(*b);
	size_a = stack_size(*a);
	printf("size_b = %d\n", size_b);
	printf("size_a = %d\n", size_a);
	// Debug
	if (size_a == lst_size || size_b == lst_size)
	{
		printf("Erreur: la partition n'a pas changé la taille des piles\n");
		return ;
	}
	// Appels récursifs pour trier les sous-piles
	if (size_a > 1)
	{
		puts("recursive a");
		print_list(a, 1);
		print_list(b, 1);
		q_sort(a, b, size_a, 'a');
	}
	if (size_b > 1)
	{
		puts("recursive b");
		print_list(a, 1);
		print_list(b, 1);
		q_sort(b, a, size_b, 'b');
	}
	printf("===vrais fin quick_sort_a_3_voies===\n");
}

// Fonction principale
int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;

	// Initialisation de la pile 'a' avec des éléments uniques
	push_element(&a, 561, 0);
	push_element(&
