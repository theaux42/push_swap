/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:19:19 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/20 20:50:31 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	syntaxe_error(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	doublons_error(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	print_error(t_stack_node **a, char **r, int reason)
{
	free_stack(a);
	ft_freesplit(r);
	ft_putstr("[\e[0;31mERROR\e[0m] ");
	if (reason == 1)
		ft_putendl("=> There is a syntax error in the list.");
	else if (reason == 2)
		ft_putendl("=> There is a value out of the int range.");
	else if (reason == 3)
		ft_putendl("=> There is a duplicate in the list.");
	else
		ft_putendl("=> How is this possible ?");
	exit(1);
}

void	error_r(int reason)
{
	ft_putstr("[\e[0;31mERROR\e[0m] ");
	if (reason == 1)
		ft_putendl(" => There is a syntax error in the list.");
	else if (reason == 2)
		ft_putendl(" => There is a value out of the int range.");
	else
		ft_putendl(" => How is this possible ?");
	exit(1);
}
