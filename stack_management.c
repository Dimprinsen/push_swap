/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2026/02/23 18:20:10 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_count(t_node *stk)
{
	t_node	*current;
	int		count;

	current = stk;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_node	*node_find_max(t_node *stk)
{
	t_node	*max;

	max = stk;
	while (stk != NULL)
	{
		if (stk->value > max->value)
			max = stk;
		stk = stk->next;
	}
	return (max);
}

t_node	*node_find_min(t_node *stk)
{
	t_node	*min;

	min = stk;
	while (stk != NULL)
	{
		if (stk->value < min->value)
			min = stk;
		stk = stk->next;
	}
	return (min);
}

int	node_append(t_node **stk, t_node *new_node)
{
	t_node	*current;

	if (stk)
	{
		if (*stk)
		{
			current = *stk;
			while (current->next != NULL)
				current = current->next;
			current->next = new_node;
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

t_node	*node_last(t_node *stk)
{
	if (!stk)
		return (NULL);
	while (stk->next != NULL)
		stk = stk->next;
	return (stk);
}
