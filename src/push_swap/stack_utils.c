/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:33:59 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/08 12:01:38 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*return_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_length(t_node *stack)
{
	int	length;

	length = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

bool	check_if_is_sorted(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_node	*find_smaller(t_node *stack)
{
	t_node	*smaller_node;
	long	smaller;

	if (!stack)
		return (NULL);
	smaller = LONG_MAX;
	while (stack)
	{
		if (stack->number < smaller)
		{
			smaller = stack->number;
			smaller_node = stack;
		}
		stack = stack->next;
	}
	return (smaller_node);
}

t_node	*find_biggest(t_node *stack)
{
	t_node	*biggest_node;	
	long	biggest;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->number > biggest)
		{
			biggest = stack->number;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}
