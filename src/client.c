/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/07 15:04:38 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

int	send_message(char **argv)
{
	int				i;
	int				j;
	unsigned int	pid;
	int				r_code;

	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		j = 128;
		while (j >= 1)
		{
			if ((argv[2][i] & j) == 0)
				r_code = kill(pid, SIGUSR1);
			else
				r_code = kill(pid, SIGUSR2);
			if (r_code == -1)
				return (-1);
			j /= 2;
			pause();
			usleep(100);
		}
		i++;
	}
	return (0);
}

void	sig_handler(int signum)
{
	(void)(signum);
	return ;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					r_code;

	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
		return (ft_printf("Invalid amount of Arguments!\n"));
	r_code = send_message(argv);
	if (r_code == -1)
		ft_printf("ERROR: check PID is correct and server is running\n");
	return (r_code);
}
