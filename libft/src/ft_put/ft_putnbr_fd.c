/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:18:51 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/23 15:57:58 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;
	char	c[10];
	int		i;

	nbl = n;
	i = 0;
	if (0 == n)
	{
		write (fd, "0", 1);
		return ;
	}
	if (nbl < 0)
	{
		nbl *= -1;
		write (fd, "-", 1);
	}
	while (nbl)
	{
		c[i++] = (nbl % 10) + 48;
		nbl /= 10;
	}
	while (i > 0)
		write (fd, &c[--i], 1);
}
