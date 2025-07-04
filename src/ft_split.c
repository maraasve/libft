/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:50:21 by maraasve          #+#    #+#             */
/*   Updated: 2025/07/04 16:54:05 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	count_words(char const *s, char c)
{
	int	word_count;
	int	letter;
	int	i;

	word_count = 0;
	i = 0;
	letter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			letter++;
		if (letter == 1 && s[i] != c)
			word_count++;
		if (s[i] == c)
			letter = 0;
		i++;
	}
	return (word_count);
}

static int	len_till_next_del(char const *s, char c)
{
	int	word_len;

	word_len = 0;
	while (s[word_len] != c && s[word_len] != '\0')
	{
		word_len++;
	}
	return (word_len);
}

char	**splitting(char **array, char const *s, char c)
{
	int		s_index;
	int		array_index;

	s_index = 0;
	array_index = 0;
	while (s[s_index] != '\0')
	{
		if (s[s_index] != c)
		{
			array[array_index] = ft_substr(s, s_index,
					len_till_next_del(&s[s_index], c));
			if (!array[array_index])
			{
				free_array(array);
				return (NULL);
			}
			s_index += len_till_next_del(&s[s_index], c);
			array_index++;
		}
		else
			s_index++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		word_count;

	word_count = count_words(s, c);
	array = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!array)
		return (NULL);
	splitting(&*array, s, c);
	return (array);
}
