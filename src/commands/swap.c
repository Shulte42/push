/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:43:07 by bruda-si          #+#    #+#             */
/*   Updated: 2024/01/08 15:01:27 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(q_stack_struct **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;//Head now point to the "second node", that now turns the first
	(*head)->prev->prev = (*head);
	(*head)->prev->next = (*head)->next;//Update the next pointer of the old first node to skip the "second" and point tho the "third"(now the second)
	if ((*head)->next)//Chekc if there's a next node
		(*head)->prev->next = (*head)->next;//if so, update its 'prev' pointer to point to the new head
	(*head)->next = (*head)->prev;//make the head->next point to the old top stakc node
	(*head)->prev = NULL;//Prev pointer of the new top node to NULL
}
void	sa(q_stack_struct **a, bool print)//rotate the top 'a' node to the bottom of the stack, and print the instruction
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(q_stack_struct **b, bool print)//rotate the top 'b' node to the bottom of the stack, and print the instruction
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(q_stack_struct **a, q_stack_struct **b, bool print)//Simultaneously rotate the top 'a' and 'b' node to the bottom of the stack, and print the instruction
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}