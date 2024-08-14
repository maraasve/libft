/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:20:50 by maraasve          #+#    #+#             */
/*   Updated: 2023/11/28 14:43:49 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *p1, size_t old, size_t new)
{
	void	*p2;

	if (!p1)
		p1 = (void *)malloc(new * sizeof(char));
	p2 = (void *)malloc(new * sizeof(char));
	if (new > old)
		ft_memcpy(p2, p1, old);
	else
		ft_memcpy(p2, p1, new);
	free(p1);
	return (p2);
}
