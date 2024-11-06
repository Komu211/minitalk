/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:19:44 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/10 15:19:30 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*trimmed;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (contains(s1[i], set))
		i++;
	while (len > 0 && contains(s1[len - 1], set) && len >= i)
		len--;
	trimmed = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!trimmed)
		return (NULL);
	while (i < len)
	{
		trimmed[j] = s1[i];
		i++;
		j++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}
