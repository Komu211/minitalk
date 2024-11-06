/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:37:52 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/15 14:19:24 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_digit(int num)
{
	char	*tmp;
	int		out_len;

	tmp = ft_itoa(num);
	if (tmp == NULL)
		return (-1);
	out_len = write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (out_len);
}

int	ft_printf_unsigned_digit(unsigned int num)
{
	char	*tmp;
	int		out_len;

	tmp = ft_uitoa(num);
	if (tmp == NULL)
		return (-1);
	out_len = write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (out_len);
}
