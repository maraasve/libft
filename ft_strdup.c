/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:55:20 by marieke           #+#    #+#             */
/*   Updated: 2023/10/10 15:55:46 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
