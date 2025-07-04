/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:14:35 by marieke           #+#    #+#             */
/*   Updated: 2025/07/04 16:54:05 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
