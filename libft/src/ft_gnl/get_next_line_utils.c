/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:56:14 by bruda-si          #+#    #+#             */
/*   Updated: 2023/11/11 19:42:08 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char	*buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
		i++;
	return (i);
}

void	*ft_nlcut(char *new_line)
{
	int	i;

	i = 0;
	while (new_line[i])
	{
		if (new_line[i++] == '\n')
		{
			new_line[i] = '\0';
			break ;
		}
	}
	return (new_line);
}

int	ft_nlhandle(char *buffer)
{
	int		i;
	int		j;
	int		nl;

	i = 0;
	j = 0;
	nl = 0;
	while (buffer[i])
	{
		if (nl == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			nl = 1;
		buffer[i] = '\0';
		i++;
	}
	return (nl);
}

char	*ft_strjoin(char *new_line, char *buffer)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = (char *)malloc(ft_strlen(new_line) + ft_strlen(buffer) + 1);
	if (!dest)
		return (NULL);
	while (new_line && new_line[i])
	{
		dest[i] = new_line[i];
		i++;
	}
	while (buffer[j])
		dest[i++] = buffer[j++];
	dest[i] = '\0';
	free(new_line);
	return (ft_nlcut(dest));
}
