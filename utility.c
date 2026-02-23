/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2026/02/23 18:20:10 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	vec_size(const char *s, char c)
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] != c)
		{
			count++;
			while (s[idx] != c && s[idx + 1] != '\0')
				idx++;
		}
		idx++;
	}
	return (count);
}

t_node	*get_previous_in_a(t_node *stk, t_node *node)
{
	t_node	*current;
	t_node	*target;

	if (node->value > (node_find_max(stk))->value)
		return (node_find_min(stk));
	target = node_find_max(stk);
	current = stk;
	while (current)
	{
		if ((current->value > node->value) && (current->value < target->value))
			target = current;
		current = current->next;
	}
	return (target);
}

static int	get_min_cost(t_node *stk_a, t_node *stk_b, t_node *current,
			t_node *target)
{
	int	sync;
	int	unsync;

	sync = get_sync_cost(stk_a, stk_b, current, target);
	unsync = get_unsync_cost(stk_a, stk_b, current, target);
	if (sync < unsync)
		return (sync);
	return (unsync);
}

t_node	*find_cheapest(t_node *stk_a, t_node *stk_b)
{
	t_node	*cheapest;
	t_node	*current;
	int		cost;
	int		temp_cost;

	cost = INT_MAX;
	current = stk_a;
	while (current)
	{
		temp_cost = get_min_cost(stk_a, stk_b, current,
				get_previous_node(stk_b, current));
		if (temp_cost < cost)
		{
			cost = temp_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
