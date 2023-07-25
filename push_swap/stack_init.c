/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenecha <csenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:24:36 by csenecha          #+#    #+#             */
/*   Updated: 2023/07/10 17:51:49 by csenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

void	stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
	long	nb;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_ac_2);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_free(a, av, flag_ac_2);
		if (error_double(*a, (int)nb))
			error_free(a, av, flag_ac_2);
		add_node(a, (int)nb);
		++i;
	}
	if (flag_ac_2)
		free_string_array(av);
}
