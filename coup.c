#include "push_swap.h"

// $ faudra faire les cas erreur pour toutes les fonctions
void	swap(t_stack **lst)
{
	int	tmp;

	tmp = (*lst)->value;
	(*lst)->value = (*lst)->next->value;
	(*lst)->next->value = tmp;
	return ;
}

void	swap_ab(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	return ;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	return ;
}

void	rotate(t_stack **head)
{
	t_stack	*temp;
	t_stack	*last;

	temp = (*head);
	(*head) = (*head)->next;
	temp->next = NULL;
	last = *head;
	while (last)
		last = last->next;
	last->next = temp;
	return ;
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate(a);
	rotateb(b);
	return ;
}

void	reverse_rotate(t_stack **head)
{
	t_stack	*prev;
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	prev = NULL;
	last = *head;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *head;
	*head = last;
}

void	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return ;
}

void	print_list(t_stack **head)
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
	return ;
}

//? test rotate_a

//? test push a et b
// int main()
// {
// 	t_stack *a;
// 	t_stack *b;

// 	a = malloc(sizeof(t_stack));
// 	a->next = malloc(sizeof(t_stack));
// 	a->value = 2;
// 	a->next->value = 4;

// 	b = malloc(sizeof(t_stack));
// 	b->next = malloc(sizeof(t_stack));
// 	b->value = 8;
// 	b->next->value = 6;

// 	puts("liste a avant push");
// 	print_list(a);
// 	puts("liste b avant push");
// 	print_list(b);
// 	push_b(&a, &b);
// 	puts("\nliste a apres push");
// 	print_list(a);
// 	puts("liste b apres push");
// 	print_list(b);
// 	puts("\n");
// 	return (0);
// }

//? test swap_ab
// int main()
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = malloc(sizeof(t_stack));
// 	a->next = malloc(sizeof(t_stack));
// 	a->value = 2;
// 	a->next->value = 4;

// 	b = malloc(sizeof(t_stack));
// 	b->next = malloc(sizeof(t_stack));
// 	b->value = 8;
// 	b->next->value = 6;

// 	printf("avant swap a->value = %d\n", a->value);
// 	printf("avant swap a->next->value = %d\n", a->next->value);
// 	printf("avant swap b->value = %d\n", b->value);
// 	printf("avant swap b->next->value = %d\n", b->next->value);
// 	swap_ab(a,b);
// 	puts("\n");
// 	printf("apres swap a->value = %d\n", a->value);
// 	printf("apres swap a->next->value = %d\n", a->next->value);
// 	printf("apres swap b->value = %d\n", b->value);
// 	printf("apres swap b->next->value = %d\n", b->next->value);
// }

//? test swap_a swap_b
// int main()
// {
// 	t_stack *a;
// 	a = malloc(sizeof(t_stack));
// 	a->next = malloc(sizeof(t_stack));
// 	a->value = 2;
// 	a->next->value = 4;
// 	printf("avant swap a->value = %d\n", a->value);
// 	printf("avant swap a->next->value = %d\n", a->next->value);
// 	swap_a(a);
// 	printf("apres swap a->value = %d\n", a->value);
// 	printf("apres swap a->next->value = %d\n", a->next->value);
// 	puts("\n");

// 	t_stack *b;
// 	b = malloc(sizeof(t_stack));
// 	b->next = malloc(sizeof(t_stack));
// 	b->value = 6;
// 	b->next->value = 8;
// 	printf("avant swap b->value = %d\n", b->value);
// 	printf("avant swap b->next->value = %d\n", b->next->value);
// 	swap_b(b);
// 	printf("apres swap b->value = %d\n", b->value);
// 	printf("apres swap b->next->value = %d\n", b->next->value);
// 	return (0);
// }