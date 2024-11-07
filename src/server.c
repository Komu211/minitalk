/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:43:13 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/07 11:56:29 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

void	sig_handler(int signum)
{
	static unsigned int	c = 0;
	static int			pos = 0;

	c = (c << 1) | (signum - SIGUSR1);
	pos++;
	if (pos == 8)
	{
		write(1, &c, 1);
		c = 0;
		pos = 0;
	}

}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
