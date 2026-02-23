/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2026/02/23 18:20:10 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stk(t_node *stk)
{
	t_node	*current;
	t_node	*temp;

	if (!stk)
		return (0);
	current = stk;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
		temp = NULL;
	}
	return (1);
}

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

void	check_numbers(t_node *stk)
{
	t_node	*current;
	t_node	*check_node;

	current = stk;
	while (current != NULL)
	{
		if (current->value < INT_MIN || current->value > INT_MAX)
		{
			write(2, "Error\n", 6);
			free_stk(stk);
			exit(0);
		}
		check_node = current->next;
		while (check_node != NULL)
		{
			if (current->value == check_node->value)
			{
				write(2, "Error\n", 6);
				free_stk(stk);
				exit(0);
			}
			check_node = check_node->next;
		}
		current = current->next;
	}
}

void	check_args(int argc, char *argv[], int should_free)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (check_str(argv[i]) == 0)
		{
			if (should_free)
				free_vector(argc, argv);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
