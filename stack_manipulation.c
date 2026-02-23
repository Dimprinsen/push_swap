/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2026/02/23 18:20:10 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_node **src, t_node **dest)
{
	t_node	*buffer;

	if (!*src || !*dest)
		return ;
	buffer = *src;
	*src = (*src)->next;
	buffer->next = *dest;
	*dest = buffer;
}

void	stack_swap(t_node **stk)
{
	t_node	*buffer;

	buffer = *stk;
	*stk = buffer->next;
	buffer->next = (*stk)->next;
	(*stk)->next = buffer;
}

int	stack_rotate(t_node **stk)
{
	t_node	*last;
	t_node	*buffer;

	if (!*stk || !(*stk)->next)
		return (0);
	buffer = *stk;
	*stk = (*stk)->next;
	last = node_last(buffer);
	buffer->next = NULL;
	last->next = buffer;
	return (1);
}

int	stack_rev_rotate(t_node **stk)
{
	t_node	*last;
	t_node	*buffer;

	if (!*stk || !(*stk)->next)
		return (0);
	last = node_last(*stk);
	buffer = *stk;
	while (buffer->next != last)
		buffer = buffer->next;
	buffer->next = NULL;
	last->next = *stk;
	*stk = last;
	return (1);
}

int	stack_sync_rotate(t_node **stk_a, t_node **stk_b)
{
	if (!stk_a || !stk_b)
		return (0);
	if (stack_rotate(stk_a) == 0 || stack_rotate(stk_b) == 0)
		return (0);
	return (1);
}
