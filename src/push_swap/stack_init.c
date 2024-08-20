/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:48:20 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/20 20:31:59 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	ft_atol(const char *s)
{
	long	res;
	int		sign;

	if (ft_strlen_no_zero(s) > 11)
		error_r(2);
	res = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

static void	add_node_to_stack(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nb = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv, char **r)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntaxe_error(argv[i]))
			print_error(a, r, 1);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			print_error(a, r, 2);
		if (doublons_error(*a, (int)n))
			print_error(a, r, 3);
		add_node_to_stack(a, (int)n);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	for_each_push(t_stack_node **stack, t_stack_node *top_n, char name)
{
	while (*stack != top_n)
	{
		if (name == 'a')
		{
			if (top_n->above_med)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name == 'b')
		{
			if (top_n->above_med)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
