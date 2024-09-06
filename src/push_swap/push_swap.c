/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:17:56 by bruda-si          #+#    #+#             */
/*   Updated: 2024/09/06 15:11:58 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	q_stack_struct *a;//To store a pointer to stack 'a'
	q_stack_struct *b;
	(void) av;
	a = NULL;
	b = NULL;
	
	if(ac == 1) //|| (ac == 2 && !av[1][0]))//Check for incorrect argument count or if the second argument is '0'
		return (1); //Return error
	// printf("hello");
	else if (ac == 2)//Chekc if the 2nd argument is not empty, thus implies a string
		av = ft_split(av[1], ' ');//Split the string in substrings
	init_stack_a(&a, av + 1, ac == 2);//Initiate the stack 'a' and handle errors
	if (!check_if_is_sorted(a))//check if the stack is sorted
	{
		if (stack_length(a) == 2) // if not sorted, and there are two numbers, swap the first two nodes
			sa(&a, false);
		else if (stack_length(a) == 3)// if not sorted, and trere are three number, use the sort three algorithm
			sort_three(&a);
		else
			sort_stack(&a, &b);//if not sorted, and there are more than 3 numbers, we call the sort algorithm
	}
	free_stack(&a);//free the stack 'a'
	return (0);
}