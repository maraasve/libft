/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_int_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:28:51 by marieke           #+#    #+#             */
/*   Updated: 2024/07/26 17:48:40 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_str_int_range(char *str)
{
	int	i;

	if (!str | !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_strlen(&str[i]) > 10)
		return (0);
	else if (ft_strlen(&str[i]) < 10)
		return (1);
	if (*str == '-')
	{
		if (ft_strncmp(&str[i], "2147483648", 10) > 0)
			return (0);
	}
	else
	{
		if (ft_strncmp(&str[i], "2147483647", 10) > 0)
			return (0);
	}
	return (1);
}
