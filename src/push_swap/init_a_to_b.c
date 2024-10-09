/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:12:37 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/09 15:12:26 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_node	*find_targed_b_node(t_node *a, t_node *b)
{
	t_node	*current_b_node;
	t_node	*target_b_node;
	long	smallest_so_far;

	current_b_node = b;
	smallest_so_far = LONG_MIN;
	while (current_b_node)
	{
		if (current_b_node->number > a->number
			&& current_b_node->number < smallest_so_far)
		{
			smallest_so_far = current_b_node->number;
			target_b_node = current_b_node;
		}
		current_b_node = current_b_node->next;
	}
	if (smallest_so_far == LONG_MIN)
		return (find_biggest(b));
	else
		return (target_b_node);
}

static void	target_a(t_node *a, t_node *b)
{
	if (!a || !b)
		return ;
	while (a)
	{
		a->target_node = find_targed_b_node(a, b);
		a = a->next;
	}
}

static void	cost_analysis_a(t_node *a, t_node *b)
{
	int	length_a;
	int	length_b;

	length_a = stack_length(a);
	length_b = stack_length(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = length_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += length_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
