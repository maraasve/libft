/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:51:48 by maraasve          #+#    #+#             */
/*   Updated: 2025/07/04 16:54:05 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	len;

	i = 0;
	dst_len = ft_strlen(dst);
	if (size <= 0 || dst_len > size)
		len = ft_strlen(src) + size;
	else
		len = ft_strlen(src) + dst_len;
	while (src[i] != '\0' && (i + dst_len + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (size > 0 && size > dst_len)
		dst[dst_len + i] = '\0';
	return (len);
}
