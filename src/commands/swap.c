/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:06:50 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/20 20:23:38 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	(*head)->prev = temp;
	if (temp->next != NULL)
		temp->next->prev = *head;
	temp->next = *head;
	temp->prev = NULL;
	*head = temp;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_putendl("sa");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_putendl("sb");
}

void	ss(t_stack_node **a, t_stack_node **b, bool p)
{
	swap(a);
	swap(b);
	if (!p)
		ft_putendl("ss");
}
