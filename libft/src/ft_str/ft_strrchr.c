/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:36:34 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/23 16:44:44 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*tmp;

	tmp = (char *)s;
	i = ft_strlen(s);
	while (i >= 0 && s[i] != (char)c)
		i--;
	if ((char)c == s[i])
		return (tmp + i);
	return (NULL);
}
