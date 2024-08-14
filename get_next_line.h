/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:26:21 by marieke           #+#    #+#             */
/*   Updated: 2024/04/30 17:06:43 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnllist
{
	char				*text;
	int					fd;
	int					pos;
	int					size;
	struct s_gnllist	*next;
}	t_gnllist;

char		*get_next_line(int fd);
t_gnllist	*new_node(t_gnllist **start, t_gnllist *node, int fd);
char		*clear_list_or_node(t_gnllist **start, t_gnllist *node, int fd);
char		*ft_strlcpy(char *dst, char *src, int size);
int			ft_my_strchr(const char *s, int c);
char		*ft_my_strjoin(t_gnllist **start, t_gnllist *node, char *dst,
				char *src);
char		*clean_up_buffer(t_gnllist **start, t_gnllist *node);

#endif