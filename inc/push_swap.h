/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:25:08 by bruda-si          #+#    #+#             */
/*   Updated: 2024/09/06 15:14:10 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include "../../libft/inc/libft.h"
# include "../../libft/inc/ft_printf.h"
# include <stdio.h>

typedef struct s_stack_node
{
	int             number;//the number to sort
	int             index;//the number position in the stack
	int             push_cost;//the total of commands
	bool        above_median;//Used to calculate the 'push_cost'
	bool        cheapest;//The node that is the cheapest to do commands
	struct s_stack_node *target_node;//The target node of a node in the oposite stack
	struct s_stack_node *prev;//A pointer to the previus node
	struct s_stack_node *next;//A pointer to the next node
}q_stack_struct;

//Handle errors
void	free_stack(q_stack_struct **stack);
void	free_errors(q_stack_struct **a, char **av, bool argc_2);
int		error_duplicate(q_stack_struct *a, int n);
int		syntax_error(char *str);

//Stack init
void    init_stack_a(q_stack_struct **a, char **av, bool argc_2);


//Init nodes
void	prepare_for_push(q_stack_struct **stack, q_stack_struct *top_node, char stack_name);
q_stack_struct *find_the_cheapest(q_stack_struct *stack);
void	init_nodes_b(q_stack_struct *a, q_stack_struct *b); //Define a function that prepares the nodes for pushing `b` to `a`
void	init_nodes_a(q_stack_struct *a, q_stack_struct *b);//Define a function that combines all the functions needed to prepare stack `a`, ready for our pushing and sorting. These functions set the data inside the node's structure
void	set_cheapest(q_stack_struct *stack); //Define a function that sets a node's `cheapest` attribute as `true` or `false`
void    current_index(q_stack_struct *stack);


//Utils
q_stack_struct *return_last_node(q_stack_struct *stack);
int	stack_length(q_stack_struct *stack);
bool	check_if_is_sorted(q_stack_struct *stack);
q_stack_struct	*find_smaller(q_stack_struct *stack);
q_stack_struct	*find_biggest(q_stack_struct *stack);

//Commands
void	sa(q_stack_struct **a, bool print);
void	sb(q_stack_struct **b, bool print);
void	ss(q_stack_struct **a, q_stack_struct **b, bool print);
void	ra(q_stack_struct **a, bool print);
void	rb(q_stack_struct **b, bool print);
void	rr(q_stack_struct **a, q_stack_struct **b, bool print);
void	rra(q_stack_struct **a, bool print);
void	rrb(q_stack_struct **b, bool print);
void	rrr(q_stack_struct **a, q_stack_struct **b, bool print);
void	pa(q_stack_struct **a, q_stack_struct **b, bool print);
void	pb(q_stack_struct **a, q_stack_struct **b, bool print);

//Algorithm
void	sort_three(q_stack_struct **a);
void	sort_stack(q_stack_struct **a, q_stack_struct **b);

#endif