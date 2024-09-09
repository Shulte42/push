/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:21:20 by bruda-si          #+#    #+#             */
/*   Updated: 2024/09/09 12:44:39 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/push_swap.h"

void	sort_three(q_stack_struct **a)
{
	q_stack_struct	*biggest_node;

	biggest_node = find_biggest(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->number > (*a)->prev->number)
		sa(a, false);
}