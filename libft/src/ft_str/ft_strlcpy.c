/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:38:07 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/09 17:05:12 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char src1[] = "lorem";
	char dst1[20];
	char dst2[20];
	int	a;
	int	b;

	a = ft_strlcpy(dst1, src1, 15);
	b = strlcpy(dst2, src1, 15);
	printf("%d, %s\n", a, dst1);
	printf("%d, %s\n", b, dst2);
	printf("%d\n", strcmp(dst1, dst2));
}*/
