/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:56:59 by marieke           #+#    #+#             */
/*   Updated: 2025/07/04 16:54:05 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	count_trim(char const *s1, char const *set, size_t index)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1[index] == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;

	begin = 0;
	end = ft_strlen(s1);
	while (count_trim(s1, set, begin) && begin < end)
		begin++;
	while (count_trim(s1, set, end - 1) && end > begin)
		end--;
	return (ft_substr(s1, begin, end - begin));
}
