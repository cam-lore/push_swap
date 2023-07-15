/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenecha <csenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:36:12 by csenecha          #+#    #+#             */
/*   Updated: 2023/07/15 23:31:54 by csenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_cost;
	bool				above_middle;
	bool				cheap_node;
	struct s_stack_node	*best_friend;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;	

char				**ft_split(char *str, char separator);

void				free_string_array(char **string_array);
void				error_free(t_stack_node **a, char **argv, bool flag_argc_2);
void				free_stack(t_stack_node **stack);
int					error_double(t_stack_node *a, int nbr);
int					error_syntax(char *str_nbr);

void				stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
void				init_nodes(t_stack_node *a, t_stack_node *b);
void				set_position(t_stack_node *stack);
void				set_price(t_stack_node *a, t_stack_node *b);
void				set_cheapest(t_stack_node *b);
void				set_best_friend(t_stack_node *a, t_stack_node *b);

void				add_node(t_stack_node **stack, int nbr);
t_stack_node		*find_last_node(t_stack_node *head);
t_stack_node		*find_smallest(t_stack_node *stack);

t_stack_node		*return_cheapest(t_stack_node *stack);
bool				is_stack_sorted(t_stack_node *stack);
int					stack_len(t_stack_node *stack);
void				final_r(t_stack_node **s, t_stack_node *n, char c);
void				sort_three(t_stack_node **a);
void				sort_five(t_stack_node **a, t_stack_node **b);
void				push_swap(t_stack_node **a, t_stack_node **b);

void				sa(t_stack_node **a);
void				sb(t_stack_node **b);
void				ss(t_stack_node **a, t_stack_node **b);
void				ra(t_stack_node **a);
void				rb(t_stack_node **b);
void				rr(t_stack_node **a, t_stack_node **b);
void				rra(t_stack_node **a);
void				rrb(t_stack_node **b);
void				rrr(t_stack_node **a, t_stack_node **b);
void				pa(t_stack_node **a, t_stack_node **b);
void				pb(t_stack_node **b, t_stack_node **a);

#endif 