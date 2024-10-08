/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:33:59 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/07 13:09:46 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

q_stack_struct *return_last_node(q_stack_struct *stack)// Function that returns the pointer to the last node of the stack
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_length(q_stack_struct *stack)// Function that returns the length of the stack
{
	int	length;
	
	length = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		length++;//rotate the top 'a' node to the bottom of the stack, and print the instruction
	}
	return (length);
}
bool	check_if_is_sorted(q_stack_struct *stack)//Function that check if the stack is already sorted
{
	if (!stack)// Check if the stack is empty
		return (NULL);
	while (stack->next)//Loop until the end of the stack is reached
	{
		if (stack->number > stack->next->number)//check if the currently number is larger them the next node
			return (false);
		stack = stack->next;//Move the stack for processing
	}
	return (true);
}

q_stack_struct	*find_smaller(q_stack_struct *stack)
{
	long	smaller;//To store the minimum value so far
	q_stack_struct	*smaller_node;//Pointer to the smallest value in the stack
	
	if (!stack)
		return (NULL);
	smaller = LONG_MAX;//Assing to the smallest value so far, the long max
	while (stack)
	{
		if (stack->number < smaller)//Check if the current node valu is smaller the smallest so far
		{
			smaller = stack->number;//If so, update the biggest number so far
			smaller_node = stack;//And assing the pointer to the smallest node
		}
		stack = stack->next;//Move the stack for processing
	}
	return (smaller_node);
}

q_stack_struct *find_biggest(q_stack_struct *stack)
{
	long	biggest;
	q_stack_struct *biggest_node;	

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)//Loop until the end of the stack is reached
	{
		if (stack->number > biggest)
		{
			biggest = stack->number;//Update the biggest value so far
			biggest_node = stack;//Set the pointe to point to the node with the biggest value so far
		}
		stack = stack->next;//Move the stack for processing
	}
	return (biggest_node);
	
}