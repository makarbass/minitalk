/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:36:59 by bpatrici          #+#    #+#             */
/*   Updated: 2021/10/04 16:24:25 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int				i;
	static unsigned char	c;

	(void) context;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(siginfo->si_pid, SIGUSR2);
			usleep(100);
			ft_putchar_fd('\n', 1);
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(siginfo->si_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID is ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
