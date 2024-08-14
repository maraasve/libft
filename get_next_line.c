/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:26:11 by marieke           #+#    #+#             */
/*   Updated: 2024/04/30 17:06:12 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_up_buffer(t_gnllist **start, t_gnllist *node)
{
	int		line_len;
	char	*tmp;

	if (node->size == 0)
		return (NULL);
	line_len = node->pos;
	node->size -= line_len;
	if (node->size == 0)
	{
		free(node->text);
		node->text = NULL;
		return (NULL);
	}
	tmp = node->text;
	node->text = (char *)malloc(sizeof(char) * (node->size + 1));
	if (!node->text)
		return (clear_list_or_node(start, node, -1));
	ft_strlcpy(node->text, &tmp[node->pos], node->size);
	free(tmp);
	node->pos = 0;
	return (NULL);
}

char	*copy_buffer_to_line(t_gnllist **start, t_gnllist *node, int bytes_read)
{
	char	*line;
	int		line_len;
	int		out_strchr;

	line_len = 0;
	if (!node->text)
		return (NULL);
	out_strchr = ft_my_strchr(&node->text[node->pos], '\n');
	if ((bytes_read < BUFFER_SIZE && out_strchr == -1) || out_strchr == -1)
	{
		while (node->text[node->pos + line_len] != '\0')
			line_len++;
	}
	else
	{
		line_len = out_strchr;
		line_len++;
	}
	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (clear_list_or_node(start, node, -1));
	ft_strlcpy(line, &node->text[node->pos], line_len);
	node->pos += line_len;
	return (line);
}

char	*read_file(t_gnllist **start, t_gnllist *node, int fd, char *buffer)
{
	int		bytes_read;
	char	*line;
	char	*tmp;

	bytes_read = 1;
	while (ft_my_strchr(&node->text[node->pos], '\n') == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (clear_list_or_node(start, node, fd));
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = node->text;
		node->text = ft_my_strjoin(start, node, tmp, buffer);
		if (!node->text)
			return (clear_list_or_node(start, node, -1));
		node->size += bytes_read;
		free(tmp);
	}
	line = copy_buffer_to_line(start, node, bytes_read);
	clean_up_buffer(start, node);
	if ((bytes_read < BUFFER_SIZE && node->size == 0) || node->size == 0)
		clear_list_or_node(start, node, fd);
	return (line);
}

char	*find_or_add_fd(t_gnllist **start, int fd, char *buffer, int found)
{
	t_gnllist	*flag;
	t_gnllist	*tmp;

	tmp = NULL;
	flag = *start;
	while (flag != NULL)
	{
		if (flag->fd == fd)
		{
			found = 1;
			break ;
		}
		tmp = flag;
		flag = flag->next;
	}
	if (!found && tmp)
	{
		flag = tmp;
		flag->next = new_node(start, *start, fd);
		flag = flag->next;
	}
	if (!flag)
		return (clear_list_or_node(start, flag, -1));
	return (read_file(start, flag, fd, buffer));
}

char	*get_next_line(int fd)
{
	static t_gnllist	*start = NULL;
	char				*line;
	char				*buffer;
	int					found;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (clear_list_or_node(&start, start, -1), NULL);
	if (start == NULL)
		start = new_node(&start, start, fd);
	if (!start)
		return (NULL);
	found = 0;
	line = find_or_add_fd(&start, fd, buffer, found);
	return (free(buffer), line);
}
