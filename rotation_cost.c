/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2026/02/23 18:20:10 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_previous_node(t_node *stk, t_node *node)
{
	t_node	*current;
	t_node	*target;

	if (node->value > (node_find_max(stk))->value)
		return (node_find_max(stk));
	if (node->value < (node_find_min(stk))->value)
		return (node_find_max(stk));
	target = node_find_min(stk);
	current = stk;
	while (current)
	{
		if ((current->value < node->value) && (current->value > target->value))
			target = current;
		current = current->next;
	}
	return (target);
}

int	get_rotation_cost(t_node *stk, t_node *node)
{
	int	count;

	count = 0;
	if (stk->value == node->value)
	{
		return (count);
	}
	while (stk->value != node->value)
	{
		count++;
		stk = stk->next;
	}
	return (count);
}

int	get_rev_rotation_cost(t_node *stk, t_node *node)
{
	int	count;

	count = 0;
	if (stk->value == node->value)
	{
		return (count);
	}
	while (stk->value != node->value)
		stk = stk->next;
	while (stk)
	{
		count++;
		stk = stk->next;
	}
	return (count);
}

int	get_sync_cost(t_node *stk_a, t_node *stk_b, t_node *node,
		t_node *target)
{
	int		rot_cost;
	int		rev_rot_cost;

	if (get_rotation_cost(stk_a, node) > get_rotation_cost(stk_b, target))
	{
		rot_cost = get_rotation_cost(stk_a, node);
	}
	else
	{
		rot_cost = get_rotation_cost(stk_b, target);
	}
	if (get_rev_rotation_cost(stk_a, node) > get_rev_rotation_cost(stk_b,
			target))
	{
		rev_rot_cost = get_rev_rotation_cost(stk_a, node);
	}
	else
	{
		rev_rot_cost = get_rev_rotation_cost(stk_b, target);
	}
	if (rot_cost < rev_rot_cost)
	{
		return (rot_cost);
	}
	return (rev_rot_cost);
}

int	get_unsync_cost(t_node *stk_a, t_node *stk_b, t_node *node,
		t_node *target)
{
	int		node_cost;
	int		target_cost;

	if (get_rotation_cost(stk_a, node) < get_rev_rotation_cost(stk_a, node))
	{
		node_cost = get_rotation_cost(stk_a, node);
	}
	else
	{
		node_cost = get_rev_rotation_cost(stk_a, node);
	}
	if (get_rotation_cost(stk_b, target) < get_rev_rotation_cost(stk_b, target))
	{
		target_cost = get_rotation_cost(stk_b, target);
	}
	else
	{
		target_cost = get_rev_rotation_cost(stk_b, target);
	}
	return (node_cost + target_cost);
}
