/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:55:20 by marieke           #+#    #+#             */
/*   Updated: 2025/07/04 16:54:05 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;

	len = ft_strlen(s1);
	cpy = malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1, len + 1);
	return (cpy);
}
