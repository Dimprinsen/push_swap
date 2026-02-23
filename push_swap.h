/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:02:56 by thtinner          #+#    #+#             */
/*   Updated: 2026/02/23 18:22:23 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			value;
	struct s_stack	*next;
}	t_node;

/* ************************************************************************** */
/*                            STACK MANAGEMENT                                */
/* ************************************************************************** */

int		node_append(t_node **stk, t_node *new_node);
t_node	*node_last(t_node *stk);
t_node	*node_find_min(t_node *stk);
t_node	*node_find_max(t_node *stk);
int		node_count(t_node *stk);

/* ************************************************************************** */
/*                          BASIC STACK OPERATIONS                            */
/* ************************************************************************** */

void	stack_push(t_node **src, t_node **dest);
void	stack_swap(t_node **stk);
int		stack_rotate(t_node **stk);
int		stack_rev_rotate(t_node **stk);
int		stack_sync_rotate(t_node **stk_a, t_node **stk_b);
int		sync_rev_rotate(t_node **stk_a, t_node **stk_b);

/* ************************************************************************** */
/*                          ROTATION & MOVEMENT                               */
/* ************************************************************************** */

void	write_n_rotate(t_node **stk, t_node *node, int toggle);
void	write_n_rev_rotate(t_node **stk, t_node *node, int toggle);
void	do_sync_rotate(t_node **stk_a, t_node **stk_b, t_node *node_a,
			t_node *node_b);
void	do_sync_r_rot(t_node **stk_a, t_node **stk_b, t_node *node_a,
			t_node *node_b);
void	sync_to_top(t_node **stk_a, t_node **stk_b, t_node *node_a,
			t_node *node_b);
void	unsync_to_top(t_node **stk_a, t_node **stk_b, t_node *node_a,
			t_node *node_b);

/* ************************************************************************** */
/*                          COST CALCULATION                                  */
/* ************************************************************************** */

int		get_rotation_cost(t_node *stk, t_node *node);
int		get_rev_rotation_cost(t_node *stk, t_node *node);
int		get_sync_cost(t_node *stk_a, t_node *stk_b, t_node *node,
			t_node *target);
int		get_unsync_cost(t_node *stk_a, t_node *stk_b, t_node *node,
			t_node *target);
int		sync_r_or_rr(t_node *stk_a, t_node *stk_b, t_node *node_a,
			t_node *node_b);

/* ************************************************************************** */
/*                          ALGORITHM HELPERS                                 */
/* ************************************************************************** */

t_node	*get_previous_node(t_node *stk, t_node *node);
t_node	*get_previous_in_a(t_node *stk, t_node *node);
t_node	*find_cheapest(t_node *stk_a, t_node *stk_b);

/* ************************************************************************** */
/*                          SORTING ALGORITHM                                 */
/* ************************************************************************** */

void	solve_three_elements(t_node **stk);
t_node	*push_two_elements(t_node **stk_a);
void	push_to_stack_b(t_node **stk_a, t_node **stk_b);
void	push_to_stack_a(t_node **stk_a, t_node **stk_b);
void	order_stack_a(t_node **stk_a, t_node *min);

/* ************************************************************************** */
/*                          MEMORY & VALIDATION                               */
/* ************************************************************************** */

int		free_stk(t_node *stk);
void	free_vector(int argc, char *argv[]);
int		check_str(char *str);
void	check_args(int argc, char *argv[], int should_free);
void	check_numbers(t_node *stk);

/* ************************************************************************** */
/*                          INITIALIZATION & MAIN                             */
/* ************************************************************************** */

char	**parse_args(int *argc, char **argv);
t_node	*initialize_stack(int argc, char **vec);
void	check_if_stack_ordered(t_node *stk);
int		exec_push_swap(t_node **stk_a);
int		vec_size(const char *s, char c);

#endif
