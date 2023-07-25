/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenecha <csenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:58:01 by csenecha          #+#    #+#             */
/*   Updated: 2023/07/10 05:24:42 by csenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*find_highest(t_stack_node *stack)
{
	t_stack_node	*highest_node;
	t_stack_node	*current_node;
	int				highest_value;

	if (stack == NULL)
		return (NULL);
	highest_node = NULL;
	highest_value = INT_MIN;
	current_node = stack;
	while (current_node != NULL)
	{
		if (current_node->value > highest_value)
		{
			highest_value = current_node->value;
			highest_node = current_node;
		}
		current_node = current_node->next;
	}
	return (highest_node);
}

void	sort_three(t_stack_node **stack_a)
{
	t_stack_node	*highest_node;

	highest_node = NULL;
	highest_node = find_highest(*stack_a);
	if (highest_node != NULL && *stack_a == highest_node)
		ra(stack_a);
	else if (highest_node != NULL && (*stack_a)->next == highest_node)
		rra(stack_a);
	if (highest_node != NULL && (*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (stack_len(*stack_a) > 3)
	{
		init_nodes(*stack_a, *stack_b);
		final_r(stack_a, find_smallest(*stack_a), 'a');
		pb(stack_b, stack_a);
	}
}
