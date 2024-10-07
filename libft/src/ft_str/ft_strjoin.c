/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:39:33 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/23 16:12:04 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i_general;
	int			i;
	char		*newstr;

	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i_general = 0;
	i = 0;
	while (s1[i_general] != '\0')
	{
		newstr[i_general] = s1[i_general];
		i_general++;
	}
	while (s2[i] != '\0')
	{
		newstr[i_general] = s2[i++];
		i_general++;
	}
	newstr[i_general] = '\0';
	return (newstr);
}
