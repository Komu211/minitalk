/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:43:13 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/07 16:43:03 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned int	c = 0;
	static int			pos = 0;

	(void)(context);
	if (signum == SIGINT)
	{
		ft_printf("Closing Server...\n");
		exit(0);
		return ;
	}
	c = (c << 1) | (signum - SIGUSR1);
	pos++;
	if (pos == 8)
	{
		write(1, &c, 1);
		c = 0;
		pos = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sa.sa_mask) != 0 || sigaction(SIGUSR1, &sa, NULL) != 0
		|| sigaction(SIGUSR2, &sa, NULL) != 0 || sigaction(SIGINT, &sa,
			NULL) != 0)
	{
		ft_printf("Error setting up signal handlers\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
