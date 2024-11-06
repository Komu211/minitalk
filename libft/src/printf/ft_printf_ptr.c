/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:39:02 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/15 14:18:04 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_ptr(void *ptr, char *base)
{
	int	tmp;

	if (ptr == NULL)
		return (write(1, "0x0", 3));
	tmp = write(1, "0x", 2);
	if (tmp == -1)
		return (-1);
	tmp = ft_put_long_base((unsigned long)ptr, base);
	if (tmp == -1)
		return (-1);
	return (tmp + 2);
}
