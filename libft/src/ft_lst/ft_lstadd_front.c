/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:41:20 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/22 17:49:45 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
