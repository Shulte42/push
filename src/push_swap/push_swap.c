/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:17:56 by bruda-si          #+#    #+#             */
/*   Updated: 2024/09/09 14:53:20 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void print_numbers(q_stack_struct *a)
	{
    q_stack_struct *current = a;
    while (current != NULL) {
        printf("%d\n", current->number);
        current = current->next;
    }
}
int main(int ac, char **av)
{
	q_stack_struct *a;//To store a pointer to stack 'a'
	q_stack_struct *b;
	a = NULL;
	b = NULL;
	
	if(ac == 1 || (ac == 2 && !av[1][0])) //|| (ac == 2 && !av[1][0]))//Check for incorrect argument count or if the second argument is '0'
		return (1); //Return error
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');//Split the string in substrings
		init_stack_a(&a, av, ac == 2);
	}
	else 
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
	//
	//print_numbers(a);
	free_stack(&a);//free the stack 'a'
	return (0);
}