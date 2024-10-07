/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_coiso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:12:07 by bruda-si          #+#    #+#             */
/*   Updated: 2023/11/04 18:26:27 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char especifier, va_list ap)
{
	int	count;

	count = 0;
	if (especifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (especifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (especifier == 'p')
		count += ft_print_memory(va_arg(ap, unsigned long), 16);
	else if (especifier == 'd')
		count += ft_print_hex_dec((long)va_arg(ap, int), 10);
	else if (especifier == 'i')
		count += ft_print_hex_dec(va_arg(ap, int), 10);
	else if (especifier == 'u')
		count += ft_print_un_decimal(va_arg(ap, unsigned int), 10);
	else if (especifier == 'x')
		count += ft_print_hex_dec((long)va_arg(ap, unsigned int), 16);
	else if (especifier == 'X')
		count += ft_print_upp((long)va_arg(ap, unsigned int), 16);
	else if (especifier == '%')
		count += write(1, "%", 1);
	else
		count += write(1, &especifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else 
			count += write(1, format, 1);
		++format;
	}
	return (count);
}

// int main()
// {
//     char *str = "Hello, world!";
//     long decimal = -12345;
	// unsigned long un_decimal = 9876543210;
//     void *ptr = (void *)0x12345678;

//     printf("Original:\n");
//     printf("%%c: %c\n", 'A');
//     printf("%%s: %s\n", str);
//     printf("%%d: %d\n", (int)decimal);
//     printf("%%u: %lu\n", un_decimal);
//     printf("%%p: %p\n", ptr);

//     ft_print_str("\nCustom:\n");
//     ft_print_str("c: ");
	// ft_print_char('A');
//     ft_print_str("\n");
//     ft_print_str("%%s: ");
//     ft_print_str(str);
//     ft_print_str("\n");
//     ft_print_str("%%d: ");
//     ft_print_hex_dec(decimal, 10);
//     ft_print_str("\n");
//     ft_print_str("%%u: ");
//     ft_print_un_decimal(un_decimal, 10);
//     ft_print_str("\n");
//     ft_print_str("%%p: ");
		// ft_printf("%d", ft_printf(" %p %p ", 0, 0));
//     ft_print_str("\n");

//     return 0;
//  }