/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenecha <csenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:48:58 by csenecha          #+#    #+#             */
/*   Updated: 2023/07/15 23:31:35 by csenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack_node *stack)
{
	int				count;
	int				length;
	int				middle_line;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	count = 0;
	length = stack_len(stack);
	middle_line = length / 2;
	current = stack;
	if (stack == NULL)
		return ;
	while (current != NULL)
	{
		current->current_position = count;
		if (count <= middle_line)
			current->above_middle = 1;
		else
			current->above_middle = 0;
		current = current->next;
		count++;
	}
}

void	set_best_friend(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*best_friend;
	t_stack_node	*current_a;
	long			best_target;

	while (b != NULL)
	{
		best_friend = NULL;
		best_target = LONG_MAX;
		current_a = a;
		while (current_a != NULL)
		{
			if (current_a->value > b->value
				&& current_a->value < best_target)
			{
				best_target = current_a->value;
				best_friend = current_a;
			}
			current_a = current_a->next;
		}
		if (best_target == LONG_MAX)
			b->best_friend = find_smallest(a);
		else
			b->best_friend = best_friend;
		b = b->next;
	}
}

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->current_position;
		if (!(b->above_middle))
			b->push_cost = len_b - (b->current_position);
		if (b->best_friend->above_middle)
			b->push_cost += b->best_friend->current_position;
		else
			b->push_cost += len_a - (b->best_friend->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_target_value;
	t_stack_node	*best_best_friend;

	if (NULL == b)
		return ;
	best_target_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_target_value)
		{
			best_target_value = b->push_cost;
			best_best_friend = b;
		}
		b = b->next;
	}
	best_best_friend->cheap_node = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_best_friend(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
