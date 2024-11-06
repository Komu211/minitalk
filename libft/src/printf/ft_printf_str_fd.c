/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:07:57 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/06 13:04:08 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_fd(char *str)
{
	if (str != NULL)
		return (write(1, str, ft_strlen(str)));
	return (write(1, "(null)", 6));
}
