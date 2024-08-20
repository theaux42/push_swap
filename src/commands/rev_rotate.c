/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:02:18 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/20 20:26:01 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rrotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, bool print)
{
	rrotate(a);
	if (!print)
		ft_putendl("rra");
}

void	rrb(t_stack_node **b, bool print)
{
	rrotate(b);
	if (!print)
		ft_putendl("rrb");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool p)
{
	rrotate(a);
	rrotate(b);
	if (!p)
		ft_putendl("rrr");
}
