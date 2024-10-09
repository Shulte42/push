/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:01:58 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/09 11:00:24 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_both(q_stack_struct **a, q_stack_struct **b, 
						q_stack_struct *cheapest_node) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node && *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rr(a, b, false); //Rotate both `a` and `b` nodes
	current_index(*a);
	current_index(*b);
}

static void rotate(q_stack_struct **stack)
{
    q_stack_struct *first_node;
    q_stack_struct *last_node;

    if (!*stack || !(*stack)->next)
        return;

    first_node = *stack;
    last_node = return_last_node(*stack);

    *stack = first_node->next;
    (*stack)->prev = NULL;

    last_node->next = first_node;
    first_node->prev = last_node;
    first_node->next = NULL;
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