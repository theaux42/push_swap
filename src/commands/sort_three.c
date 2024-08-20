/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:08:41 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/20 14:40:42 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = get_max(*a);
	if (biggest == *a)
		ra(a, false);
	else if ((*a)->next == biggest)
		rra(a, false);
	if ((*a)->nb > (*a)->next->nb)
		sa(a, false);
}

void	rrotate2(t_stack_node **a, t_stack_node **b, t_stack_node *cheap_n)
{
	while (*b != cheap_n->target && *a != cheap_n)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
