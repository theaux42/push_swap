/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:53:46 by tbabou            #+#    #+#             */
/*   Updated: 2024/08/17 15:09:55 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_words(char *str, char delimeter) {
  int words;
  bool is_word;

  words = 0;
  while (*str) {
    is_word = false;
    while (*str == delimeter)
      ++str;
    while (*str != delimeter && *str) {
      if (!is_word) {
        ++words;
        is_word = true;
      }
      ++str;
    }
  }
  return (words);
}

static char	*get_next_word(char *str, char delimeter, char **r) {
  static int cursor = 0;
  char *next;
  int i;
  int len;

  i = 0;
  len = 0;
  while (str[cursor] == delimeter)
    ++cursor;
  while ((str[cursor + len] != delimeter) && str[cursor + len])
    ++len;
  next = malloc((size_t)len * sizeof(char) + 1);
  if (!next) {
    leak(r);
    exit(1);
  }
  while ((str[cursor] != delimeter) && str[cursor])
    next[i++] = str[cursor++];
  next[i] = '\0';
  return (next);
}

char	**ps_split(char *s, char c) {
  char **result_array;
  int words_count;
  int i;

  i = 0;
  words_count = count_words(s, c);
  if (!words_count)
    error_r();
  result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
  if (!result_array)
    return (NULL);
  while (words_count-- >= 0) {
    if (i == 0) {
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

void	leak(char **splitted) {
  int i;

  i = 0;
  if (splitted == NULL)
    return ;
  while (splitted[i] != NULL) {
    free(splitted[i]);
    i++;
  }
  free(splitted);
}
