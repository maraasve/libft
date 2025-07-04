/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:49:36 by marieke           #+#    #+#             */
/*   Updated: 2025/07/04 16:53:43 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((int)count < 0 && (int)size < 0)
		return (NULL);
	if (count * size >= 4294967295)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (p);
	ft_bzero(p, size * count);
	return (p);
}
