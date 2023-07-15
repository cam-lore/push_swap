/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenecha <csenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:45:49 by csenecha          #+#    #+#             */
/*   Updated: 2023/07/10 06:00:04 by csenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **pos_end, t_stack_node **pos_start)
{
	t_stack_node	*node_to_push;

	if (*pos_start == NULL)
		return ;
	node_to_push = *pos_start;
	*pos_start = (*pos_start)->next;
	if (*pos_start)
		(*pos_start)->prev = NULL;
	node_to_push->prev = NULL;
	if (*pos_end == NULL)
	{
		*pos_end = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *pos_end;
		node_to_push->next->prev = node_to_push;
		*pos_end = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
