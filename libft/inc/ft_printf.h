/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:07:44 by bruda-si          #+#    #+#             */
/*   Updated: 2024/01/11 18:03:34 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_un_decimal(long nbr, int base);
int	ft_print_memory(long nbr, int base);
int	ft_print_str(char *str);
int	ft_print_hex_dec(long long nbr, int base);
int	ft_print_char(int c);
int	ft_print_upp(long long nbr, int base);
#endif