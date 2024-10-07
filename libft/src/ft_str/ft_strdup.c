/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:05:59 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/13 18:50:52 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*n_str;

	n_str = (char *)malloc(ft_strlen(s) + 1);
	if (!n_str)
		return (NULL);
	ft_memcpy((void *)n_str, (const void *)s, ft_strlen(s));
	n_str[ft_strlen(s)] = '\0';
	return (n_str);
}
