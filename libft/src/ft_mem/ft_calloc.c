/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:37:29 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/13 16:54:10 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem_alloc;

	mem_alloc = malloc(nmemb * size);
	if (mem_alloc == NULL)
		return (NULL);
	ft_bzero(mem_alloc, nmemb * size);
	return (mem_alloc);
}
