/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_esc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:20:12 by maraasve          #+#    #+#             */
/*   Updated: 2024/02/16 15:10:15 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	is_espace_char(char c)
{
	if (c == '\'' || c == '\"' || c == '\\' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\b' || c == '\f' || c == '\a' || c == '\0')
		return (1);
	return (0);
}

size_t	ft_strlcpy_esc(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		if (src[i] == '\\' && is_espace_char(src[i +1]))
			i++;
		else
		{
			dst[j] = src[i];
			i++;
			j++;
		}
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
