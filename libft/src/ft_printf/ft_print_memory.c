/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:00:27 by bruda-si          #+#    #+#             */
/*   Updated: 2024/01/11 18:05:00 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_memory(long nbr, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (nbr == 0)
		return (ft_print_str("(nil)"));
	count += ft_print_str("0x");
	if (nbr < 0)
	{
		write (1, "-", 1);
		return (ft_print_hex_dec(-nbr, base) + 1);
	}
	if (nbr < (long)base)
		return (count += ft_print_char(symbols[nbr]));
	else
	{
		count += ft_print_hex_dec(nbr / base, base);
		return (count += ft_print_hex_dec(nbr % base, base));
	}
}
