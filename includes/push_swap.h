/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:22:48 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/21 00:39:05 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	bool				cheapest;
	bool				above_med;
	int					push_cost;
	int					nb;
	int					index;

	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}						t_stack_node;

// functions in sort_stacks.c
void					turk_sort(t_stack_node **a, t_stack_node **b);
// functions in stack_init.c
void					for_each_push(t_stack_node **stack, t_stack_node *top_n,
							char name);
void					init_stack_a(t_stack_node **a, char **argv, char **r);
t_stack_node			*get_cheapest(t_stack_node *stack);
// functions in sort_three.c
void					sort_three(t_stack_node **a);
void					rrotate2(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheap_n);
// functions in b_2_a.c
void					init_node_b(t_stack_node *a, t_stack_node *b);
// functions in a_2_b.c
void					init_node_a(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *stack);
void					current_index(t_stack_node *stack);
// functions in error.c
void					print_error(t_stack_node **a, char **r, int reason);
int						doublons_error(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
int						syntaxe_error(char *str_n);
void					error_r(int reason);
// functions in push_swap.c
int						ft_strlen_no_zero(const char *s);
// functions in strings.c
void					ft_putstr(char *str);
void					ft_putendl(char *str);
void					ft_putnbr(int n);
// functions in tools.c
int						get_stack_len(t_stack_node *stack);
bool					is_sorted(t_stack_node *stack);
t_stack_node			*get_last(t_stack_node *stack);
t_stack_node			*get_max(t_stack_node *stack);
t_stack_node			*get_min(t_stack_node *stack);
// function in split.c
int						ft_countwords(char *str, char delimeter);
char					*get_next_word(char *str, char delimeter, char **r);
char					**ft_split(char *s, char c);
void					ft_freesplit(char **splitted);
// commands of push_swap
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool p);
void					rrr(t_stack_node **a, t_stack_node **b, bool p);
void					pa(t_stack_node **a, t_stack_node **b, bool p);
void					pb(t_stack_node **a, t_stack_node **b, bool p);
void					rr(t_stack_node **a, t_stack_node **b, bool p);

#endif