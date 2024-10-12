/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:19:04 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/12 12:37:32 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] != sep && str[i] != '\0')
			i++;
		words++;
	}
	return (words);
}

int	ft_wordlen(const char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

static void	free_list(char **list, int position)
{
	while (position >= 0)
	{
		free(list[position]);
		position--;
	}
	free(list);
}

char	**ft_split(char const *s, char c)
{
	int			position;
	int			words;
	char		**list;

	words = ft_count_words(s, c);
	list = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	list[words] = 0;
	position = 0;
	while (words > 0)
	{
		while (*s == c)
			s++;
		list[position] = ft_substr(s, 0, ft_wordlen(s, c));
		if (!list[position])
		{
			free_list(list, position - 1);
			return (NULL);
		}
		s += ft_wordlen(s, c);
		position++;
		words--;
	}
	return (list);
}
