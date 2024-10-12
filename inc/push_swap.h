/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:25:08 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/12 11:50:45 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include <stdio.h>

typedef struct s_stack_node
{
	int					number;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_node;

//Handle errors
void	free_stack(t_node **stack);
void	free_errors(t_node **a, char **av, bool argc_2);
void	free_mat(char **av);
int		error_duplicate(t_node *a, int n);
int		syntax_error(char *str);
//Stack init
void	init_stack_a(t_node **a, char **av, bool argc_2);
//Init nodes
void	prepare_for_push(t_node **stack, t_node *top_node, char stack_name);
t_node	*find_the_cheapest(t_node *stack);
void	init_nodes_b(t_node *a, t_node *b);
void	init_nodes_a(t_node *a, t_node *b);
void	set_cheapest(t_node *stack);
void	current_index(t_node *stack);
//Utils
t_node	*return_last_node(t_node *stack);
int		stack_length(t_node *stack);
bool	check_if_is_sorted(t_node *stack);
t_node	*find_smaller(t_node *stack);
t_node	*find_biggest(t_node *stack);

//Commands
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);
void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **a, t_node **b, bool print);
//Algorithm
void	sort_three(t_node **a);
void	sort_stack(t_node **a, t_node **b);

#endif