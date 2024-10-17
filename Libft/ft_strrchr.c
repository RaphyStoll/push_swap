/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:32:21 by raphael           #+#    #+#             */
/*   Updated: 2024/08/01 13:59:27 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count])
	{
		count++;
	}
	if (c == '\0')
		return ((char *)&s[count]);
	while (count >= 0)
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count--;
	}
	return (0);
}
