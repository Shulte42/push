/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:16:17 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/23 16:00:28 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*b_s1;
	const unsigned char	*b_s2;
	size_t				i;

	b_s1 = (const unsigned char *)s1;
	b_s2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (b_s1[i] != b_s2[i])
			return (b_s1[i] - b_s2[i]);
		i++;
	}
	return (0);
}
