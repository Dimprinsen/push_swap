/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2025/10/11 02:03:00 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sync_rotate(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	while (*stk_a != nd_a && *stk_b != nd_b)
	{
		stack_sync_rotate(stk_a, stk_b);
		write(1, "rr\n", 3);
	}
	while (*stk_a != nd_a)
	{
		stack_rotate(stk_a);
		write(1, "ra\n", 3);
	}
	while (*stk_b != nd_b)
	{
		stack_rotate(stk_b);
		write(1, "rb\n", 3);
	}
}

void	do_sync_r_rot(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	while (*stk_a != nd_a && *stk_b != nd_b)
	{
		sync_rev_rotate(stk_a, stk_b);
		write(1, "rrr\n", 4);
	}
	while (*stk_a != nd_a)
	{
		stack_rev_rotate(stk_a);
		write(1, "rra\n", 4);
	}
	while (*stk_b != nd_b)
	{
		stack_rev_rotate(stk_b);
		write(1, "rrb\n", 4);
	}
}

int	sync_r_or_rr(t_stk *stk_a, t_stk *stk_b, t_stk *nd_a, t_stk *nd_b)
{
	int		rotation;
	int		rev_rotation;

	rotation = get_rotation_cost(stk_a, nd_a);
	rev_rotation = get_rev_rotation_cost(stk_a, nd_a);
	if (get_rotation_cost(stk_b, nd_b) > rotation)
		rotation = get_rotation_cost(stk_b, nd_b);
	if (get_rev_rotation_cost(stk_b, nd_b) > rev_rotation)
		rev_rotation = get_rev_rotation_cost(stk_b, nd_b);
	if (rotation < rev_rotation)
		return (1);
	return (0);
}

void	sync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	if (sync_r_or_rr(*stk_a, *stk_b, nd_a, nd_b) == 1)
	{
		do_sync_rotate(stk_a, stk_b, nd_a, nd_b);
	}
	else
	{
		do_sync_r_rot(stk_a, stk_b, nd_a, nd_b);
	}
}

void	unsync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	if (get_rotation_cost(*stk_a, nd_a) < get_rev_rotation_cost(*stk_a, nd_a))
	{
		write_n_rotate(stk_a, nd_a, 1);
	}
	else
	{
		write_n_rev_rotate(stk_a, nd_a, 1);
	}
	if (get_rotation_cost(*stk_b, nd_b) < get_rev_rotation_cost(*stk_b, nd_b))
	{
		write_n_rotate(stk_b, nd_b, 0);
	}
	else
	{
		write_n_rev_rotate(stk_b, nd_b, 0);
	}
}
