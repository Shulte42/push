/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:29:52 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/12 13:54:52 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../inc/push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	syntax_error(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->number == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_mat(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i++]);
	}
}

void	free_errors(t_node **a, char **av, bool argc_2)
{
	free_stack(a);
	if (argc_2)
		free_mat(av);
	write(2, "Error\n", 6);
	exit(1);
}
