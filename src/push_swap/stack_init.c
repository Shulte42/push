/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:14:30 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/09 17:09:05 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	static_atoi(const char *string, t_node **a,
					char **av, bool argc_2)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*string == ' ' || *string == '\t' || *string == '\n' || \
			*string == '\r' || *string == '\f' || *string == '\v')
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign = -1;
		string++;
	}
	while (ft_isdigit(*string))
		result = result * 10 + (*string++ - '0');
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		free_errors(a, av, argc_2);
	return (result * sign);
}

static void	append_node(t_node **stack, int number)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->number = number;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = return_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_node **a, char **av, bool argc_2)
{
	long	number;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			free_errors(a, av, argc_2);
		number = static_atoi(av[i], a, av, argc_2);
		if (number > INT_MAX || number < INT_MIN)
			free_errors(a, av, argc_2);
		if (error_duplicate(*a, (int)number))
			free_errors(a, av, argc_2);
		append_node(a, (int)number);
		i++;
	}
}

void	prep_for_push(t_node **stack,
						t_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	prepare_for_push(t_node **stack,
						t_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
