/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:49:41 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/26 01:28:38 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//compte les caracteres d'une chaine
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//ecrit un caractere
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//ecrit un nombre
void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
