/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:35:28 by marieke           #+#    #+#             */
/*   Updated: 2023/10/10 13:47:47 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*index;

	if (!lst)
		return (NULL);
	index = lst;
	while (index->next != NULL)
	{
		index = index->next;
	}
	return (index);
}
