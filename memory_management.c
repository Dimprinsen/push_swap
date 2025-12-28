/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2025/10/11 02:03:00 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Basic function that check all chars are numbers. */
int	check_str(char *str)
{
	int	k;

	k = 0;
	if (str[k] == '\0')
		return (0);
	if (str[k] == '-' && str[k + 1] != '\0')
		k++;
	while (str[k] != '\0')
	{
		if (str[k] < '0' || str[k] > '9')
			return (0);
		k++;
	}
	return (1);
}

/* Applies the check_str to each node */
void	check_args(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (check_str(argv[i]) == 0)
		{
			free_vector(argc, argv);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

/* Goes through the linked list and checks for invalid numbers */
void	check_numbers(t_stk *stk)
{
	t_stk	*curr;
	t_stk	*compare;

	curr = stk;
	while (curr != NULL)
	{
		if (curr->nbr < INT_MIN || curr->nbr > INT_MAX)
		{
			write(2, "Error\n", 6);
			free_stk(stk);
			exit(0);
		}
		compare = curr->next;
		while (compare != NULL)
		{
			if (curr->nbr == compare->nbr)
			{
				write(2, "Error\n", 6);
				free_stk(stk);
				exit(0);
			}
			compare = compare->next;
		}
		curr = curr->next;
	}
}

/* Function used to free any given linked list stk */
int	free_stk(t_stk *stk)
{
	t_stk	*cur;
	t_stk	*tmp;

	if (!stk)
		return (0);
	cur = stk;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
	return (1);
}

/* Function used to free created vector in case of arg error */
void	free_vector(int argc, char *argv[])
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (i < argc)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
