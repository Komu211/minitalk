/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:33:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/08 11:48:07 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	int		i;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	jstr = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!jstr)
		return (NULL);
	while (i < len && s1[i] != '\0')
	{
		jstr[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		jstr[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	jstr[i] = '\0';
	return (jstr);
}
