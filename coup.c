#include "push_swap.h"

// $ faudra faire les cas erreur pour toutes les fonctions 
void swap_a(t_stack *a)
{
	int	tmp;
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	return;
}

void swap_b(t_stack *b)
{
	int	tmp;
	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	return;
}

void swap_ab(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
	return;
}

void push_a(t_stack **a, t_stack **b)
{
	t_stack *temp;
	
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;

}

void push_b(t_stack **a, t_stack **b)
{
	t_stack *temp;
	
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void rotate(t_stack **a, t_stack **b)
{

}

void print_list(t_stack *head)
{
    t_stack *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

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