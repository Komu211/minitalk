/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:12:47 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/11 13:10:32 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len_sep(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static int	get_split_num(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (get_len_sep(&s[i], c) > 0 && s[i] != c)
		{
			count++;
			i += get_len_sep(&s[i], c);
		}
		else
			i++;
	}
	return (count);
}

static int	get_next_split_pos(char const *s, char c, int n)
{
	int	i;
	int	sep_count;

	i = 0;
	sep_count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && sep_count < n)
	{
		if (s[i] == c)
		{
			sep_count++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	int		i;
	int		j;

	i = 0;
	splits = malloc((get_split_num(s, c) + 1) * sizeof(char *));
	if (!splits)
		return (NULL);
	while (i < get_split_num(s, c))
	{
		j = get_next_split_pos(s, c, i);
		splits[i] = malloc((get_len_sep(&s[j], c) + 1) * sizeof(char));
		if (!splits[i])
		{
			while (i-- > 0)
				free(splits[i]);
			return (free(splits), NULL);
		}
		ft_strlcpy(splits[i], &s[j], get_len_sep(&s[j], c) + 1);
		i++;
	}
	splits[i] = NULL;
	return (splits);
}
