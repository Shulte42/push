/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:29:51 by bruda-si          #+#    #+#             */
/*   Updated: 2023/11/04 18:28:05 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upp(long long nbr, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (nbr < 0)
	{
		write (1, "-", 1);
		return (ft_print_upp(-nbr, base) + 1);
	}
	if (nbr < base)
		return (ft_print_char(symbols[nbr]));
	else
	{
		count = ft_print_upp(nbr / base, base);
		return (count + ft_print_upp(nbr % base, base));
	}
}
