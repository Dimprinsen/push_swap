/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2025/10/11 02:03:00 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*stk_get_last(t_stk *stk)
{
	if (!stk)
		return (NULL);
	while (stk->next != NULL)
		stk = stk->next;
	return (stk);
}

int	stk_add_end(t_stk **stk, t_stk *new_node)
{
	t_stk	*curr;

	if (stk)
	{
		if (*stk)
		{
			curr = *stk;
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new_node;
			return (1);
		}
		else
		{
			*stk = new_node;
			return (1);
		}
	}
	return (0);
}

t_stk	*stk_get_min(t_stk *stk)
{
	t_stk	*min;

	min = stk;
	while (stk != NULL)
	{
		if (stk->nbr < min->nbr)
			min = stk;
		stk = stk->next;
	}
	return (min);
}

t_stk	*stk_get_max(t_stk *stk)
{
	t_stk	*max;

	max = stk;
	while (stk != NULL)
	{
		if (stk->nbr > max->nbr)
			max = stk;
		stk = stk->next;
	}
	return (max);
}

int	stk_cnt_nds(t_stk *stk)
{
	t_stk	*cur;
	int		result;

	cur = stk;
	result = 0;
	while (cur)
	{
		result++;
		cur = cur->next;
	}
	return (result);
}
