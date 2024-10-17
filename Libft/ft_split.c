/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:17:42 by raphael           #+#    #+#             */
/*   Updated: 2024/07/29 16:17:54 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_substring;
	int	i;

	count = 0;
	in_substring = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (s[i] == c)
			in_substring = 0;
		i++;
	}
	return (count);
}

static char	*get_next_word(char const *s, char c, int *index)
{
	int	start;
	int	len;

	while (s[*index] && s[*index] == c)
		(*index)++;
	start = *index;
	while (s[*index] && s[*index] != c)
		(*index)++;
	len = *index - start;
	return (ft_substr(s, start, len));
}

static char	**allocate_and_fill(char const *s, char c)
{
	char	**split;
	int		count;
	int		index;
	int		i;
	char	*word;

	count = count_words(s, c);
	split = malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	index = 0;
	i = 0;
	while (i < count)
	{
		word = get_next_word(s, c, &index);
		if (!word)
		{
			free_split(split, i);
			return (NULL);
		}
		split[i] = word;
		i++;
	}
	split[count] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (allocate_and_fill(s, c));
}
