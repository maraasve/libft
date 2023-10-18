/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:50:29 by marieke           #+#    #+#             */
/*   Updated: 2023/10/10 13:47:24 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*index;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	index = ft_lstlast(*lst);
	index->next = new;
}
