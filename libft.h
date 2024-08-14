/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:05:46 by maraasve          #+#    #+#             */
/*   Updated: 2024/07/26 14:32:42 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

long int	ft_atoi(char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_is_str_nb(char *str);
int			ft_str_int_range(char *str);
int			ft_memcmp(void *s1, void *s2, size_t n);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			ft_strcmp_nb(char *s1, char *s2);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_lstsize(t_list *lst);
int			ft_biggestnum(int a, int b);
int			ft_abs(int num);

char		*ft_itoa(int n);
char		**ft_split(char *s, char c);
char		*ft_stchr(char *s, int c);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strmapi(char *s, char (*f)(unsigned int, char));
char		*ft_strnstr(char *haystack, char *needle, size_t len);
char		*ft_strchr(char *s, int c);
char		*ft_strrchr(char *s, int c);
char		*ft_strtrim(char *s1, char *set);
char		*ft_substr(char *s, unsigned int start, size_t len);

size_t		ft_strlcat(char *dst, char *src, size_t size);
//size_t		ft_strlcpy(char *dst, char *src, size_t size);
size_t		ft_strlcpy_esc(char *dst, char *src, size_t size);
size_t		ft_strlen(char *s);
size_t		ft_countdigits(size_t num);

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memchr(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, void *src, size_t n);
void		*ft_memmove(void *dest, void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif