/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:05:32 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/09 10:01:25 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(q_stack_struct *a, q_stack_struct *b) //Define a function that sets for the current `a` node, its target node from stack `a`
{
	q_stack_struct	*current_a; //To store the pointer to the current `a` node
	q_stack_struct	*target_node; //To store the pointer of the target node for `b` node
	long			best_match_index; //To store the "closest bigger" number so far

	while (b)
	{
		best_match_index = LONG_MAX; //Set the current best match to the max long
		current_a = a; //Assign the pointer to point to the current `a` node
		while (current_a) //While the pointer is not set to NULL
		{
			if (current_a->number > b->number 
				&& current_a->number < best_match_index) //Check if the `a` node's value is bigger than `b` node, && smaller than the "closest bigger" so far
			{
				best_match_index = current_a->number; //Set the best match as the value in the current `a` node
				target_node = current_a; //Set `b` node's target node pointer to point to the current `a` node
			}
			current_a = current_a->next; //Move to the next `a` node for processing
		}
		if (best_match_index == LONG_MAX) //If the best match value has not changed
			b->target_node = find_smaller(a); //Set `b` node's target node pointer to point to the smallest number in stack `a`
		else
			b->target_node = target_node; //If the best match value has been updated, then we have a target node for the current `b` node
		b = b->next; //Move to the next `b` node for processing
	}
}

void	init_nodes_b(q_stack_struct *a, q_stack_struct *b) //Define a function that prepares the nodes for pushing `b` to `a`
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	init_nodes_a(q_stack_struct *a, q_stack_struct *b) //Define a function that combines all the functions needed to prepare stack `a`, ready for our pushing and sorting. These functions set the data inside the node's structure
{
	current_index(a);
	current_index(b);
	target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}