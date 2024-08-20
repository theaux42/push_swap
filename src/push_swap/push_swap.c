/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:45:52 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/20 14:46:33 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	parsing(t_stack_node **a, int argc, char **argv)
{
	char	**split;

	if (argc < 2)
		exit(1);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			exit(1);
		init_stack_a(a, split + 1, split);
		ft_freesplit(split);
	}
	else
		init_stack_a(a, argv + 1, NULL);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	parsing(&a, argc, argv);
	if (!is_sorted(a))
	{
		if (get_stack_len(a) == 2)
			sa(&a, false);
		else if (get_stack_len(a) == 3)
			sort_three(&a);
		else
			turk_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}

int	ft_strlen_no_zero(const char *s)
{
	int	i;
	int	index;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	index = 0;
	while (s[index])
		index++;
	return (index - i);
}
