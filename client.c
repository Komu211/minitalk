/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/05 14:51:42 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static int	ft_isspace(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-num);
	return (num);
}

int	main(int argc, char **argv)
{
	int				i;
	int				j;
	unsigned int	pid;

	i = 0;
	if (argc != 3)
		return (write(1, "Invalid amount of Arguments!\n", 29), 1);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		j = 128;
		while (j >= 1)
		{
			if ((argv[2][i] & j) == 0)
				kill(pid, SIGUSR1);
			else
			{
				kill(pid, SIGUSR2);
			}
			j /= 2;
			usleep(200);
		}
		i++;
	}
	return (0);
}
