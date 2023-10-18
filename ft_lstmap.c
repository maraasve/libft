/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:28:39 by marieke           #+#    #+#             */
/*   Updated: 2023/10/10 14:03:31 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp_list;

	if (!lst || !f || !del)
		return (NULL);
	tmp_list = ft_lstnew(f(lst->content));
	if (!tmp_list)
		return (NULL);
	new_list = tmp_list;
	lst = lst->next;
	while (lst)
	{
		tmp_list->next = ft_lstnew(f(lst->content));
		if (!tmp_list->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		tmp_list = tmp_list->next;
		lst = lst->next;
	}
	return (new_list);
}
