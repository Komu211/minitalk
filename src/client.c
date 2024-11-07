/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/07 16:32:43 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

static int	send_message(char **argv)
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

static void	sig_handler(int signum)
{
	(void)(signum);
	return ;
}

static int	check_only_numbers(char *pid)
{
	int	i;

	i = 0;
	if (ft_strlen(pid) == 0 || pid[0] == '0')
		return (0);
	while (pid[i])
	{
		if ((pid[i] < '0' || pid[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					r_code;

	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	if (argc != 3)
		return (ft_printf("Invalid amount of Arguments!\n"));
	if (!check_only_numbers(argv[1]))
	{
		ft_printf("Only use positive digits (> 0, no leading 0)for the PID!\n");
		return (-1);
	}
	if (sigemptyset(&sa.sa_mask) != 0 || sigaction(SIGUSR1, &sa, NULL) != 0)
	{
		ft_printf("Error setting up signal handlers\n");
		return (1);
	}
	r_code = send_message(argv);
	if (r_code == -1)
		ft_printf("ERROR: check PID is correct and server is running\n");
	return (r_code);
}
