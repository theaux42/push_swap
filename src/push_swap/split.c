/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:53:46 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/21 00:42:47 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**ft_split(char *s, char c)
{
	char	**result_array;
	int		wordcount;
	int		i;

	i = 0;
	wordcount = ft_countwords(s, c);
	if (!wordcount)
		error_r(1);
	result_array = malloc(sizeof(char *) * (size_t)(wordcount + 2));
	if (!result_array)
		return (NULL);
	while (wordcount-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c, result_array);
	}
	result_array[i] = NULL;
	return (result_array);
}

int	ft_countwords(char *str, char delimeter)
{
	int		wordcount;
	bool	is_word;

	wordcount = 0;
	while (*str)
	{
		is_word = false;
		while (*str == delimeter)
			++str;
		while (*str != delimeter && *str)
		{
			if (!is_word)
			{
				++wordcount;
				is_word = true;
			}
			++str;
		}
	}
	return (wordcount);
}

char	*get_next_word(char *str, char delimeter, char **r)
{
	static int	current = 0;
	char		*next;
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (str[current] == delimeter)
		++current;
	while ((str[current + len] != delimeter) && str[current + len])
		++len;
	next = malloc((size_t)len * sizeof(char) + 1);
	if (!next)
	{
		ft_freesplit(r);
		exit(1);
	}
	while ((str[current] != delimeter) && str[current])
		next[i++] = str[current++];
	next[i] = '\0';
	return (next);
}

void	ft_freesplit(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}
