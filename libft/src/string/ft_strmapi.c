/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:00:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/10 10:12:42 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mstr;

	i = 0;
	mstr = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!mstr)
		return (NULL);
	while (s[i])
	{
		mstr[i] = (*f)(i, s[i]);
		i++;
	}
	mstr[i] = '\0';
	return (mstr);
}
