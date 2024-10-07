/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:07:14 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/21 11:48:41 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*int main()
{
    t_list  *node;
    t_list  *new_node;
    char    str[] = "qualquer coisa";
    char    str2[] = "brunno";
    char    str3[] = "laskdfkas";
    node = ft_lstnew(str);
    //ft_lstadd_front(&node, ft_lstnew(str3));
    ft_lstadd_front(&node, ft_lstnew(str2));
    while (node)
    {
        printf("%s\n", (char *)node->content);
        node = node->next;    
    }
    return (0);
}*/