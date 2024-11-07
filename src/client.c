/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/07 12:54:22 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

void	send_message(char **argv)
{
	int				i;
	int				j;
	unsigned int	pid;

	i = 0;
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
			pause();
		}
		i++;
	}
}

void	sig_handler(int signum)
{
	(void)(signum);
	return ;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
		return (write(1, "Invalid amount of Arguments!\n", 29), 1);
	send_message(argv);
	return (0);
}
