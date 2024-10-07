/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:04:30 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/22 17:44:10 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countsize(int x)
{
	int	i;

	i = 0;
	if (x == 0)
		return (1);
	if (x < 0)
		i += 1;
	while (x != 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int c)
{
	unsigned int	len;
	unsigned int	number;
	char			*new;

	number = 0;
	len = ft_countsize(c);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	if (c < 0)
	{
		new[0] = '-';
		number = -c;
	}
	else
		number = c;
	if (number == 0)
		new[0] = '0';
	new[len] = '\0';
	while (number != 0)
	{
		new[(len--) - 1] = (number % 10) + '0';
		number /= 10;
	}
	return (new);
}
