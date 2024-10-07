/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:12:38 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/09 17:07:00 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*m_dest;
	unsigned char	*m_src;

	m_src = (unsigned char *)src;
	m_dest = (unsigned char *)dest;
	if (m_src == m_dest)
		return (dest);
	if (m_dest < m_src)
		ft_memcpy(m_dest, m_src, n);
	else
	{
		m_src += n;
		m_dest += n;
		while (n > 0)
		{
			*(--m_dest) = *(--m_src);
			n--;
		}
	}
	return (dest);
}
