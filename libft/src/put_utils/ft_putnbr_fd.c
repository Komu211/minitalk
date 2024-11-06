/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:33:24 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/10 14:48:30 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		if (num == -2147483648)
			return (11);
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		cpy;
	char	num[10];

	cpy = n;
	if (n < 0)
	{
		if (n == -2147483648)
			return ((void)write(fd, "-2147483648", 11));
		write(fd, "-", 1);
		n = -n;
	}
	len = get_num_len(n);
	while (len-- > 0)
	{
		num[len] = ('0' + (n % 10));
		n = n / 10;
	}
	write(fd, num, get_num_len(cpy));
}
