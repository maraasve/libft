/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:16:51 by maraasve          #+#    #+#             */
/*   Updated: 2023/11/10 16:32:40 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	digit_count;

	digit_count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digit_count++;
	}
	return (digit_count);
}

char	*ft_itoa(int n)
{
	char		*num_str;
	int			digit_count;
	long int	num;

	num = ft_abs(n);
	digit_count = count_digits(n);
	if (n < 0)
		digit_count++;
	num_str = (char *)ft_calloc(digit_count + 1, sizeof(char));
	if (!num_str)
		return (NULL);
	if (n < 0)
		num_str[0] = '-';
	if (n == 0)
		num_str[0] = '0';
	while (num > 0)
	{
		num_str[digit_count - 1] = num % 10 + '0';
		num /= 10;
		digit_count--;
	}
	return (num_str);
}
