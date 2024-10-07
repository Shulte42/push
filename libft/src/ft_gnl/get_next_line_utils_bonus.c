/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:11:23 by bruda-si          #+#    #+#             */
/*   Updated: 2023/11/11 19:41:59 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int ft_strlen(char *buffer)
{
	int lenght;
	
	lenght = 0;
	if (!buffer)
		return (0);
	while (buffer[lenght])
		lenght++;
	return (lenght);
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
	int	i;
	int	j;
	int	nl;

	i = 0;
	j = 0;
	nl = 0;
	while (buffer[i])
	{
		if (nl == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == nl)
			nl = 1;
		buffer[i] = '\0';
		i++;
	}
	return (nl);
}

char    *ft_strjoin(char *new_line, char *buffer)
{
	char    *dest;
	int     i;
	int     g;
	
	i = 0;
	g = 0;
	dest = (char *)malloc(ft_strlen(new_line) + ft_strlen(buffer) + 1);
	if (!dest)
		return (NULL);
	while(new_line && new_line[i])
	{
		dest[i] = new_line[i];
		i++;
	}
	while (buffer[g])
		dest[i++] = buffer[g++];
	dest[i] = '\0';
	free(new_line);
	return (ft_nlcut(dest));
}
