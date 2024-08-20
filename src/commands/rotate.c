/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:54:47 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/20 20:24:09 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = get_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_putendl("ra");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_putendl("rb");
}

void	rr(t_stack_node **a, t_stack_node **b, bool p)
{
	rotate(a);
	rotate(b);
	if (!p)
		ft_putendl("rr");
}
