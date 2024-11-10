/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:43:05 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/10 12:22:13 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// fonction pour switch entre les differents algo selon la taille de la liste
void	switch_algo(t_stack **stack_a, t_stack **stack_b, int lst_size)
{
	if (lst_size <= 5 && lst_size > 0)
		small_algo(stack_a, stack_b, lst_size);
	if (lst_size <= 500 && lst_size > 5)
		radix_sort(stack_a, stack_b, lst_size);
		//q_sort(stack_a, stack_b, lst_size, 'a');
	// if (lst_size <= 500 && lst_size > 100)
	// 	sort_all(stack_a, stack_b, lst_size);
	// if (lst_size > 500)
	// 	sort_all(stack_a, stack_b, lst_size);
}

// fonction principale
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	int lst_size; //? si manque une ligne stocker dans argc apres split de ""
	if (argc == 1)
		return (0);
	stack_a = create_stack(argc, argv);
	stack_b = NULL;
	if (stack_a == NULL || stack_b != NULL)
		ft_exit_error();
	lst_size = stack_size(stack_a);
	//printf("lst_size = %d\n", lst_size);
	assign_indices(stack_a, lst_size);
	if (is_sorted(stack_a))
		return (0);
	print_list(&stack_a); //$ print list indice
	print_list(&stack_b); //$ print list indice
	switch_algo(&stack_a, &stack_b, lst_size);
	//puts("===END===");
	print_list(&stack_a); //$ print list end
	print_list(&stack_b); //$ print list end
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
