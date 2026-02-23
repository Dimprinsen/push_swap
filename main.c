/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2026/02/23 18:41:49 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_stack_ordered(t_node *stk)
{
	t_node	*current;
	long	value;

	current = stk;
	value = INT_MIN;
	while (current)
	{
		if (current->value < value)
			return ;
		value = current->value;
		current = current->next;
	}
	free_stk(stk);
	exit(0);
}

t_node	*initialize_stack(int argc, char **vec)
{
	t_node	*stk_a;
	t_node	*new_node;
	int		i;

	stk_a = NULL;
	i = 0;
	while (i < argc)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		new_node->value = ft_atol(vec[i]);
		new_node->next = NULL;
		i++;
		if (node_append(&stk_a, new_node) == 0)
			return (NULL);
	}
	return (stk_a);
}

int	exec_push_swap(t_node **stk_a)
{
	t_node	*stk_b;

	if (!*stk_a)
		return (0);
	if (node_count(*stk_a) == 3)
	{
		solve_three_elements(stk_a);
		order_stack_a(stk_a, node_find_min(*stk_a));
		free_stk(*stk_a);
		return (1);
	}
	stk_b = push_two_elements(stk_a);
	push_to_stack_b(stk_a, &stk_b);
	solve_three_elements(stk_a);
	push_to_stack_a(stk_a, &stk_b);
	order_stack_a(stk_a, node_find_min(*stk_a));
	free_stk(stk_b);
	free_stk(*stk_a);
	return (1);
}

char	**parse_args(int *argc, char **argv)
{
	char	**vec;

	if (*argc == 2)
	{
		vec = ft_split(argv[1], ' ');
		if (!vec)
			return (NULL);
		*argc = vec_size(argv[1], ' ');
	}
	else
	{
		vec = argv + 1;
		*argc -= 1;
	}
	return (vec);
}

int	main(int argc, char *argv[])
{
	t_node	*stk_a;
	char	**vec;
	int		should_free;

	if (argc == 1)
		return (0);
	should_free = (argc == 2);
	vec = parse_args(&argc, argv);
	if (!vec)
		return (0);
	check_args(argc, vec, should_free);
	stk_a = initialize_stack(argc, vec);
	check_numbers(stk_a);
	check_if_stack_ordered(stk_a);
	exec_push_swap(&stk_a);
	return (0);
}
