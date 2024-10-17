/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:28:03 by raphael           #+#    #+#             */
/*   Updated: 2024/07/28 17:02:41 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		count;
	int		count2;

	count = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (s1[count])
	{
		dest[count] = s1[count];
		count++;
	}
	count2 = count;
	count = 0;
	while (s2[count])
	{
		dest[count2] = s2[count];
		count++;
		count2++;
	}
	dest[count2] = '\0';
	return (dest);
}
