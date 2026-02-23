/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2026/02/23 18:56:23 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sync_rotate(t_node **stk_a, t_node **stk_b, t_node *node_a,
		t_node *node_b)
{
	while (*stk_a != node_a && *stk_b != node_b)
	{
		stack_sync_rotate(stk_a, stk_b);
		write(1, "rr\n", 3);
	}
	while (*stk_a != node_a)
	{
		stack_rotate(stk_a);
		write(1, "ra\n", 3);
	}
	while (*stk_b != node_b)
	{
		stack_rotate(stk_b);
		write(1, "rb\n", 3);
	}
}

void	do_sync_r_rot(t_node **stk_a, t_node **stk_b, t_node *node_a,
		t_node *node_b)
{
	while (*stk_a != node_a && *stk_b != node_b)
	{
		sync_rev_rotate(stk_a, stk_b);
		write(1, "rrr\n", 4);
	}
	while (*stk_a != node_a)
	{
		stack_rev_rotate(stk_a);
		write(1, "rra\n", 4);
	}
	while (*stk_b != node_b)
	{
		stack_rev_rotate(stk_b);
		write(1, "rrb\n", 4);
	}
}

int	sync_r_or_rr(t_node *stk_a, t_node *stk_b, t_node *node_a,
		t_node *node_b)
{
	int		rotation;
	int		rev_rotation;

	rotation = get_rotation_cost(stk_a, node_a);
	rev_rotation = get_rev_rotation_cost(stk_a, node_a);
	if (get_rotation_cost(stk_b, node_b) > rotation)
		rotation = get_rotation_cost(stk_b, node_b);
	if (get_rev_rotation_cost(stk_b, node_b) > rev_rotation)
		rev_rotation = get_rev_rotation_cost(stk_b, node_b);
	return (rotation < rev_rotation);
}

void	sync_to_top(t_node **stk_a, t_node **stk_b, t_node *node_a,
		t_node *node_b)
{
	if (sync_r_or_rr(*stk_a, *stk_b, node_a, node_b))
		do_sync_rotate(stk_a, stk_b, node_a, node_b);
	else
		do_sync_r_rot(stk_a, stk_b, node_a, node_b);
}

void	unsync_to_top(t_node **stk_a, t_node **stk_b, t_node *node_a,
		t_node *node_b)
{
	if (get_rotation_cost(*stk_a, node_a) < get_rev_rotation_cost(*stk_a,
			node_a))
		write_n_rotate(stk_a, node_a, 1);
	else
		write_n_rev_rotate(stk_a, node_a, 1);
	if (get_rotation_cost(*stk_b, node_b) < get_rev_rotation_cost(*stk_b,
			node_b))
		write_n_rotate(stk_b, node_b, 0);
	else
		write_n_rev_rotate(stk_b, node_b, 0);
}
