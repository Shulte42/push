/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:01:58 by bruda-si          #+#    #+#             */
/*   Updated: 2024/09/09 14:29:34 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void     rotate(q_stack_struct **stack)
{
	q_stack_struct *last_node;//Pointer to store the last node

	if (!*stack || !(*stack)->next)
		return ;
	last_node = return_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(q_stack_struct **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(q_stack_struct **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}


void	rr(q_stack_struct **a, q_stack_struct **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}