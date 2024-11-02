/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:43:05 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/31 19:35:08 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction pour switch entre les differents algo selon la taille de la liste
void switch_algo(t_stack **stack_a, t_stack **stack_b, int lst_size, int fd)
{
	if (lst_size <= 5 && lst_size > 0)
		small_algo(stack_a, stack_b, lst_size, fd);
	//if (lst_size <= 100 && lst_size > 5)
	//	quick_sort_a_3_voies(stack_a, stack_b, lst_size, fd);
	// if (lst_size <= 500 && lst_size > 100)
	// 	sort_all(stack_a, stack_b, lst_size, fd);
	// if (lst_size > 500)
	// 	sort_all(stack_a, stack_b, lst_size, fd);
}

//fonction principale
int	main(int argc, char **argv)
{
	int		fd;
	t_stack	*stack_a;
	t_stack *stack_b;
	int lst_size; //? si manque une ligne stocker dans argc apres split de ""

	if (argc == 1)
		return (0);
	fd = 1;
	stack_a = create_stack(argc, argv);
	stack_b = NULL;
	if (stack_a == NULL || stack_b != NULL)
		ft_exit_error();
	lst_size = stack_size(stack_a);
	(void)lst_size;
	assign_indices(stack_a, argc - 1);
	if (is_sorted(stack_a))
		return (0);
	print_list(&stack_a, fd);	//$ print list indice
	print_list(&stack_b, fd);	//$ print list indice
	pa(&stack_a, &stack_b, fd);
	//switch_algo(&stack_a, &stack_b, lst_size, fd);
	print_list(&stack_a, fd);	//$ print list end
	print_list(&stack_b, fd);	//$ print list end
	return (0);
}
