/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:40:42 by bruda-si          #+#    #+#             */
/*   Updated: 2024/09/07 15:22:23 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static q_stack_struct *return_second_last_node(q_stack_struct *stack)
{
    while (stack && stack->next && stack->next->next)
        stack = stack->next;
    return stack;
}

static void rev_rotate(q_stack_struct **stack)
{
    q_stack_struct *last_node;
    q_stack_struct *second_last_node;

    if (!*stack || !(*stack)->next)
        return;

    last_node = return_last_node(*stack);
    second_last_node = return_second_last_node(*stack);

    if (second_last_node)
        second_last_node->next = NULL;

    last_node->prev = NULL;
    last_node->next = *stack;
    (*stack)->prev = last_node;
    *stack = last_node;
}

void	rra(q_stack_struct **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(q_stack_struct **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(q_stack_struct **a, q_stack_struct **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
