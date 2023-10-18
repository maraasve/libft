/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:14:35 by marieke           #+#    #+#             */
/*   Updated: 2023/10/10 13:18:49 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*index;

	if (!lst || !f)
		return ;
	index = lst;
	while (index != NULL)
	{
		f(index->content);
		index = index->next;
	}
}
