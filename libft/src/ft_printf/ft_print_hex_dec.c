/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:59:37 by bruda-si          #+#    #+#             */
/*   Updated: 2023/11/04 18:24:53 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_dec(long long nbr, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (nbr < 0)
	{
		write (1, "-", 1);
		return (ft_print_hex_dec(-nbr, base) + 1);
	}
	if (nbr < base)
		return (ft_print_char(symbols[nbr]));
	else
	{
		count = ft_print_hex_dec(nbr / base, base);
		return (count + ft_print_hex_dec(nbr % base, base));
	}
}
