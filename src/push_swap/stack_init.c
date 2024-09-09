/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:14:30 by bruda-si          #+#    #+#             */
/*   Updated: 2024/09/09 12:11:02 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long static_atoi(const char *string)//Define function that convert any string to a long value
{
	long	result;
	int	sign;
	
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
	return(result * sign);
}

static void append_node(q_stack_struct **stack, int number)
{
	q_stack_struct	*node;//to store a pointer to the new node to be created with the value 'number'
	q_stack_struct	*last_node;//To store a pointer to tthe current last node of the stack

	if (!stack)
		return ;
	node = malloc(sizeof(q_stack_struct));//Alocate memory for the new node
	if (!node)
		return ;
	node->next = NULL; //Set the next pointer of the new node to NULL, because will be the last node of the list
	node->number = number; //Alocate the argument inside the node
	if (!(*stack))//Check if the stack if empty or pointing to NULL, in these case a first node needs to be found
	{
		*stack = node;//Set the stack pointer to the new node, actualy making the new node the head of the list
		node->prev = NULL;//Set the 'prev' node to NULL, as it`s the first node
	}
	else//If the stack is not empty, we have to append the new node to the currently last node of the list
	{
		last_node = return_last_node(*stack);//Find the last node 
		last_node->next = node;//Appende the new node to the last node
		node->prev = last_node;//Update the previus pointer of the new node and complete the appending
	}
}

void    init_stack_a(q_stack_struct **a, char **av, bool argc_2)// Function that initiate the stack
{
	long number;//Variable to store the number
	int i;
	
	i = 0;
	while(av[i])
	{
		if (syntax_error(av[i]))//Check for syntax errors
			free_errors(a, av, argc_2);
		number = static_atoi(av[i]);//Take the string and pass to integer
		if (number > INT_MAX || number < INT_MIN)//Check for overflow
			free_errors(a, av, argc_2);
		if (error_duplicate(*a, (int)number))//Check if there are duplicate numbers
			free_errors(a, av, argc_2);
		append_node(a, (int)number);//if no errors, append the node to a linked list by, taking a pointer to stack 'a', create a new node and assign 'n' to that new node
		i++;
	}
	
}

q_stack_struct *find_the_cheapest(q_stack_struct *stack)//define a function that search a stack and returns the cheapest node
{	
	if (!stack)//Always is a good pratice check if the stack is empty
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)//Bool condition that check if the currently node are the cheapest move
			return (stack);
		stack = stack->next;//Move the stack for processing
	}
	return (NULL);
}

void	prep_for_push(q_stack_struct **stack,
						q_stack_struct *top_node,
						char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}

void	prepare_for_push(q_stack_struct **stack,
						q_stack_struct *top_node,
						char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}