/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:44:52 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/09 17:04:49 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_both(t_node **a, t_node **b,
						t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_node **a,
								t_node **b,
								t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_the_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prepare_for_push(a, cheapest_node, 'a');
	prepare_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	min_on_top(t_node **a)
{
	while ((*a)->number != find_smaller(*a)->number)
	{
		if (find_smaller(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stack(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_length(*a);
	if (len_a-- > 3 && !check_if_is_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !check_if_is_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !check_if_is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		prepare_for_push(a, (*b)->target_node, 'a');
		pa(a, b, false);
	}
	current_index(*a);
	min_on_top(a);
}
