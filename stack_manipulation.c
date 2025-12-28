/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2025/10/11 02:03:00 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stk **src, t_stk **dest)
{
	t_stk	*buf;

	if (!*src || !*dest)
		return ;
	buf = *src;
	*src = (*src)->next;
	buf->next = *dest;
	*dest = buf;
}

void	stack_swap(t_stk **stk)
{
	t_stk	*buf;

	buf = *stk;
	*stk = buf->next;
	buf->next = (*stk)->next;
	(*stk)->next = buf;
}

int	stack_rotate(t_stk **stk)
{
	t_stk	*last;
	t_stk	*buf;

	if (!*stk || !(*stk)->next)
		return (0);
	buf = *stk;
	*stk = (*stk)->next;
	last = stk_get_last(buf);
	buf->next = NULL;
	last->next = buf;
	return (1);
}

int	stack_rev_rotate(t_stk **stk)
{
	t_stk	*last;
	t_stk	*buf;

	if (!*stk || !(*stk)->next)
		return (0);
	last = stk_get_last(*stk);
	buf = *stk;
	while (buf->next != last)
		buf = buf->next;
	buf->next = NULL;
	last->next = *stk;
	*stk = last;
	return (1);
}

int	stack_sync_rotate(t_stk **stk_a, t_stk **stk_b)
{
	if (!stk_a || !stk_b)
		return (0);
	if (stack_rotate(stk_a) == 0 || stack_rotate(stk_b) == 0)
		return (0);
	return (1);
}
