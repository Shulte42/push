/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:17:56 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/12 13:30:55 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	handle_arguments(int ac, char **av, t_node **a)
{
	char	**split_av;
	int		i;

	split_av = NULL;
	if (ac == 2)
	{
		split_av = ft_split(av[1], ' ');
		init_stack_a(a, split_av, ac == 2);
	}
	else
		init_stack_a(a, av + 1, ac == 2);
	if (ac == 2 && split_av)
	{
		i = 0;
		while (split_av[i])
		{
			free(split_av[i]);
			i++;
		}
		free(split_av);
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	handle_arguments(ac, av, &a);
	if (!check_if_is_sorted(a))
	{
		if (stack_length(a) == 2)
			sa(&a, false);
		else if (stack_length(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
