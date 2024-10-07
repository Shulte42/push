/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:09:23 by bruda-si          #+#    #+#             */
/*   Updated: 2023/11/04 18:31:20 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_un_decimal(long nbr, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (nbr < (long)base)
		return (ft_print_char(symbols[nbr]));
	else
	{
		count = ft_print_hex_dec(nbr / base, base);
		return (count + ft_print_hex_dec(nbr % base, base));
	}
}
