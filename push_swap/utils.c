/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenecha <csenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:56:12 by csenecha          #+#    #+#             */
/*   Updated: 2023/07/16 00:51:08 by csenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

bool	is_stack_sorted(t_stack_node *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	add_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap_node)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack_node *stack)
{
	int				len;
	t_stack_node	*current;

	len = 0;
	current = stack;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;
	unsigned int	_;

	i = 0;
	while (s[i] != '\0')
	{
		_ = write(fd, &s[i], 1);
		(void)_;
		i++;
	}	
}
