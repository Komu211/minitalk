/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:36:30 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/11 14:01:06 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_ptr;
	unsigned char	*dst_ptr;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	src_ptr = (unsigned char *)src;
	dst_ptr = (unsigned char *)dst;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}
