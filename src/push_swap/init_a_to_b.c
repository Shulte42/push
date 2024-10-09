/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:12:37 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/09 10:48:05 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    current_index(q_stack_struct *stack)
{
	int i;//index of the node inside the stack
	int median;//to store the medium of the stack

	i = 0;
	if (!stack)
		return ;
	median = stack_length(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static q_stack_struct	*find_target(q_stack_struct *a, q_stack_struct *b)
{
	q_stack_struct	*current_b_node;
	q_stack_struct	*target_b_node;
	long			smallest_so_far;

	smallest_so_far = LONG_MIN;
	current_b_node = b;
	while (current_b_node)
	{
		if (current_b_node->number < a->number 
			&& current_b_node->number > smallest_so_far)
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

void	target_a(q_stack_struct *a, q_stack_struct *b)
{
	if (!a || !b)
		return ;
	while (a)
	{
		a->target_node = find_target(a, b);
		a = a->next;
	}
}

void	cost_analysis_a(q_stack_struct *a, q_stack_struct *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	length_a; //To store the lengthgth of stack `a`
	int	length_b; //To store the lengthgth of stack `b`

	length_a = stack_length(a);
	length_b = stack_length(b);
	while (a) //Loop through each node until the end of the stack is reached
	{
		a->push_cost = a->index; //Assign the current `a` node's push cost, its' index value
		if (!(a->above_median)) //Check if the above_median data is false, meaning it is below median
			a->push_cost = length_a - (a->index); //If so, update `a` node's push cost to the stack's lengthgth - index
		if (a->target_node->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			a->push_cost += a->target_node->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->push_cost += length_b - (a->target_node->index); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(q_stack_struct *stack) //Define a function that sets a node's `cheapest` attribute as `true` or `false`
{
	long			cheapest_value; //To store the value of the cheapest node so far
	q_stack_struct	*cheapest_node; //To store a pointer to the cheapest node so far

	if (!stack) //Check for an empty stack
		return ;
	cheapest_value = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	while (stack) //Loop through every node until the end of the stack is reached, and we find the cheapest node
	{
		if (stack->push_cost < cheapest_value) //Check if the current node's push cost is cheaper than the cheapest value so far
		{
			cheapest_value = stack->push_cost; //If so, update the cheapest value to the current node's push cost
			cheapest_node = stack; //Assign the current node as the cheapest node so far
		}
		stack = stack->next; //Move to the next node for comparison
	}
	cheapest_node->cheapest = true; //After iterating through the stack, if no cheaper node is found than the current, then set the cheapest node's `cheapest` attribut to `true` in the data structure
}

