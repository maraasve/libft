/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:44:05 by marieke           #+#    #+#             */
/*   Updated: 2023/10/10 13:49:06 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*index;
	int		count;

	index = lst;
	count = 0;
	while (index != NULL)
	{
		count++;
		index = index->next;
	}
	return (count);
}
