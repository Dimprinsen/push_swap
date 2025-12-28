/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2025/10/11 02:03:00 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_stack_ordered(t_stk *stk)
{
	t_stk	*cur;
	long	nbr;

	cur = stk;
	nbr = INT_MIN;
	while (cur)
	{
		if (cur->nbr < nbr)
			return ;
		nbr = cur->nbr;
		cur = cur->next;
	}
	free_stk(stk);
	exit(0);
}

t_stk	*initialize_stack(int argc, char **vec)
{
	t_stk	*stk_a;
	t_stk	*new_node;
	int		i;

	stk_a = NULL;
	i = 0;
	while (i < argc)
	{
		new_node = malloc(sizeof(t_stk));
		if (!new_node)
			return (NULL);
		new_node->nbr = ft_atol(vec[i]);
		new_node->next = NULL;
		i++;
		if (stk_add_end(&stk_a, new_node) == 0)
			return (NULL);
	}
	return (stk_a);
}

int	exec_push_swap(t_stk **stk_a)
{
	t_stk	*stk_b;

	if (!*stk_a)
		return (0);
	if (stk_cnt_nds(*stk_a) == 3)
	{
		solve_three_elements(stk_a);
		order_stack_a(stk_a, stk_get_min(*stk_a));
		free_stk(*stk_a);
		return (1);
	}
	stk_b = push_two_elements(stk_a);
	push_to_stack_b(stk_a, &stk_b);
	solve_three_elements(stk_a);
	push_to_stack_a(stk_a, &stk_b);
	order_stack_a(stk_a, stk_get_min(*stk_a));
	free_stk(stk_b);
	free_stk(*stk_a);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stk	*stk_a;
	char	**vec;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		vec = ft_split(argv[1], ' ');
		if (!vec)
			return (0);
		argc = vec_size(argv[1], ' ');
	}
	else
	{
		vec = argv + 1;
		argc -= 1;
	}
	check_args(argc, vec);
	stk_a = initialize_stack(argc, vec);
	check_numbers(stk_a);
	check_if_stack_ordered(stk_a);
	exec_push_swap(&stk_a);
	return (0);
}
