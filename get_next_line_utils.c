/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:27:46 by marieke           #+#    #+#             */
/*   Updated: 2024/03/25 15:39:26 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_my_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_my_strjoin(t_gnllist **start, t_gnllist *node, char *dst, char *src)
{
	char	*tmp;
	int		src_len;
	int		dst_len;

	src_len = 0;
	dst_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (dst && dst[dst_len] != '\0')
		dst_len++;
	tmp = (char *)malloc(sizeof(char) * (src_len + dst_len + 1));
	if (!tmp)
		return (clear_list_or_node(start, node, -1), NULL);
	if (dst)
		ft_strlcpy(tmp, dst, dst_len);
	ft_strlcpy(&tmp[dst_len], src, src_len);
	return (tmp);
}

char	*ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*clear_list_or_node(t_gnllist **start, t_gnllist *node, int fd)
{
	t_gnllist	*flag;
	t_gnllist	*tmp;

	flag = *start;
	if (fd == -1)
	{
		while (flag)
		{
			free(flag->text);
			tmp = flag->next;
			free(flag);
			flag = tmp;
		}
		return (NULL);
	}
	if (flag == node)
		*start = flag->next;
	else if (flag->next != NULL)
	{
		while (flag->next != node)
			flag = flag->next;
		flag->next = node->next;
	}
	return (free(node->text), free(node), node = NULL, NULL);
}

t_gnllist	*new_node(t_gnllist **start, t_gnllist *node, int fd)
{
	t_gnllist	*new;

	new = (t_gnllist *)malloc(sizeof(t_gnllist));
	if (!new)
		return (clear_list_or_node(start, node, -1), NULL);
	new->fd = fd;
	new->pos = 0;
	new->size = 0;
	new->text = NULL;
	new->next = NULL;
	return (new);
}
