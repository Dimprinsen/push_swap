/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2026/02/23 18:45:30 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_n_rotate(t_node **stk, t_node *node, int toggle)
{
	while (*stk != node)
	{
		if (toggle)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
		stack_rotate(stk);
	}
}

void	write_n_rev_rotate(t_node **stk, t_node *node, int toggle)
{
	while (*stk != node)
	{
		if (toggle)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
		stack_rev_rotate(stk);
	}
}

int	sync_rev_rotate(t_node **stk_a, t_node **stk_b)
{
	if (!stk_a || !stk_b)
		return (0);
	if (!stack_rev_rotate(stk_a) || !stack_rev_rotate(stk_b))
		return (0);
	return (1);
}
