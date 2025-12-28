/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2025/10/11 02:03:00 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	vec_size(const char *s, char c)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (result);
}

t_stk	*get_previous_in_a(t_stk *stk, t_stk *node)
{
	t_stk	*curr;
	t_stk	*previous;

	if (node->nbr > (stk_get_max(stk))->nbr)
		return (stk_get_min(stk));
	previous = stk_get_max(stk);
	curr = stk;
	while (curr)
	{
		if ((curr->nbr > node->nbr) && (curr->nbr < previous->nbr))
			previous = curr;
		curr = curr->next;
	}
	return (previous);
}

static int	get_min_cost(t_stk *stk_a, t_stk *stk_b, t_stk *cur, t_stk *prev)
{
	int	sync;
	int	unsync;

	sync = get_sync_cost(stk_a, stk_b, cur, prev);
	unsync = get_unsync_cost(stk_a, stk_b, cur, prev);
	if (sync < unsync)
		return (sync);
	return (unsync);
}

t_stk	*find_cheapest(t_stk *stk_a, t_stk *stk_b)
{
	t_stk	*cheapest;
	t_stk	*cur;
	int		cost;
	int		tmp_cost;

	cost = INT_MAX;
	cur = stk_a;
	while (cur)
	{
		tmp_cost = get_min_cost(stk_a, stk_b, cur,
				get_previous_node(stk_b, cur));
		if (tmp_cost < cost)
		{
			cost = tmp_cost;
			cheapest = cur;
		}
		cur = cur->next;
	}
	return (cheapest);
}
