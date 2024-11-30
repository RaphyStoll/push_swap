/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:43:05 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/11/14 14:57:06 by raphaelferr      ###   ########.fr       */
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
}

// fonction principale
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		lst_size;

	if (argc == 1)
		return (0);
	stack_a = create_stack(argc, argv);
	stack_b = NULL;
	if (stack_a == NULL || stack_b != NULL)
		ft_exit_error();
	lst_size = stack_size(stack_a);
	assign_indices(stack_a, lst_size);
	if (is_sorted(stack_a))
		return (0);
	switch_algo(&stack_a, &stack_b, lst_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
