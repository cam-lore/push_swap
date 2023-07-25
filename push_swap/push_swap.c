/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenecha <csenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:47:07 by csenecha          #+#    #+#             */
/*   Updated: 2023/07/15 23:27:37 by csenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->best_friend && *b != cheapest_node)
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->best_friend && *b != cheapest_node)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

void	final_r(t_stack_node **stack,
							t_stack_node *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_middle)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_middle)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_middle
		&& cheapest_node->best_friend->above_middle)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_middle)
		&& !(cheapest_node->best_friend->above_middle))
		reverse_rotate_both(a, b, cheapest_node);
	final_r(b, cheapest_node, 'b');
	final_r(a, cheapest_node->best_friend, 'a');
	pa(a, b);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_middle)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
