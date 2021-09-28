/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:36:59 by bpatrici          #+#    #+#             */
/*   Updated: 2021/09/24 13:54:36 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int position_digit;

void	sig_handler(int sig_num, siginfo_t *siginfo, void *context)
{
	(void) siginfo;
	(void) context;
	char 		symbol;

	if (sig_num == SIGUSR2)
		symbol |= 1 << position_digit;
	position_digit++;
	usleep(45);
	kill((int)siginfo->si_pid, SIGUSR1);
	if (position_digit == 8)
	{
		position_digit = 0;
		if (!symbol)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(symbol, 1);
		symbol = 0;
	}
}

int	main(void)
{
	struct sigaction	sg;
	int					pid;

	pid = getpid();
	ft_putstr_fd("Server PID is ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sg.sa_flags = SA_SIGINFO;
	sg.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sg, NULL);
	sigaction(SIGUSR2, &sg, NULL);
	while (1)
		pause();
	return (0);
}

