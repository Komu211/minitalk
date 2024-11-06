/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:23:26 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/14 14:32:19 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = get_num_len(n);
	num = malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len--] = '\0';
	while (len >= 0)
	{
		num[len--] = ('0' + (n % 10));
		n /= 10;
	}
	return (num);
}
