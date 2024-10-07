/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:28:29 by bruda-si          #+#    #+#             */
/*   Updated: 2023/11/11 19:42:04 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*new_line;
	int			i;

	i = 0;
	new_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		while (buffer[i])
			buffer[i] = '\0';
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		new_line = ft_strjoin(new_line, buffer);
		if (ft_nlhandle(buffer) == 1)
			break ;
	}
	return (new_line);
}

// int	main(void)
// {
// 	char	*buffer;
// 	int		fd;
// 	// int		chars_read;

// 	fd = open("text.txt", O_RDONLY);
// 	while (1)
// 	{
// 		buffer = get_next_line(fd);
// 		if (!buffer)
// 			break;
// 		printf("%s", buffer);
// 		free(buffer);
// 	}
// 	close(fd);
// 	return (0);
//  }