/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/06 14:16:14 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

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
