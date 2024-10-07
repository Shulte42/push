/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:30:04 by bruda-si          #+#    #+#             */
/*   Updated: 2023/11/11 20:18:01 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
	static char buffer[FDNUM][BUFFER_SIZE];
	char    *new_line;
	int     i;
	// int		chars_read;
	
	new_line = NULL;
	i = 0;
	// chars_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		while (buffer[fd][i])
			buffer[fd][i] = '\0';
		return (NULL);
	}
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		if (read(fd, 0, 0) < 0)
		{
			free(new_line);
			return (NULL);
		}	
		new_line = ft_strjoin(new_line, buffer[fd]);
		if (ft_nlhandle(buffer[fd]) == 1)
			break ;
	}
	return (new_line);
}

// int	main(void)
// {
// 	char	*buffer;
// 	int		fd;
// 	int		fd2;
// 	int		fd3;

// 	fd = open("text.txt", O_RDONLY);
// 	fd2 = open("text2.txt", O_RDONLY);
// 	fd3 = open("text3.txt", O_RDONLY);
// 	while (1)
// 	{
// 		buffer = get_next_line(fd);
// 		if (!buffer)
// 			break;
// 		printf("%s\n", buffer);
// 		buffer = get_next_line(fd2);
// 		if (!buffer)
// 			break;
// 		printf("%s\n", buffer);
// 		buffer = get_next_line(fd3);
// 		if (!buffer)
// 			break;
// 		printf("%s\n", buffer);
// 		free(buffer);
// 	}
// 	close(fd);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
//  }