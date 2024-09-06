/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:29:52 by bruda-si          #+#    #+#             */
/*   Updated: 2024/09/06 15:17:38 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "push_swap.h"

void    free_stack(q_stack_struct **stack)
{
	q_stack_struct  *current;
	q_stack_struct  *tmp;//To store the next node of the stack before is freed
	
	if (!stack)//Check if the stack is empty
		return ;
	current = *stack;
	printf("%d", current->number);
	while (stack)
	{
		tmp = current->next;//Assign the current next node to the "tmp"
		current->number = 0;
		free(current);//Free the current node
		current = tmp;//ann finally assing to the current the node saved in the "tmp"
	}
	if (tmp)
		printf("a\n");
		
	*stack = NULL;//set the stack pointer to the null
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

int	error_duplicate(q_stack_struct *stack, int n)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->number == n)//check if the currnt
			return (1);
		stack = stack->next;//move to the next node for checking
	}
	return (0);
}
void	free_mat(char **av)
{
	int	i;
	
	i = 0;
	while(av[i])
	{
		free(av[i++]);
	}
}
void	free_errors(q_stack_struct **a, char **av, bool argc_2) //Define a function that, upon encountering a unique error, to free the stack and print an error message
{
	free_stack(a);
	if (argc_2)
		free_mat(av);
	ft_printf("Error\n");
	exit(1);
}