/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:13:01 by maraasve          #+#    #+#             */
/*   Updated: 2025/07/04 16:54:05 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result_string;
	int		i;

	i = 0;
	result_string = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	while (s[i] != '\0')
	{
		result_string[i] = f(i, s[i]);
		i++;
	}
	return (result_string);
}
