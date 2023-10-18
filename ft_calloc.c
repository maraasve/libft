/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:49:36 by marieke           #+#    #+#             */
/*   Updated: 2023/10/10 13:08:47 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
