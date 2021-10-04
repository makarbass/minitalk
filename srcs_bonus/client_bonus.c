/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bouns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:36:19 by bpatrici          #+#    #+#             */
/*   Updated: 2021/10/04 16:24:42 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sig_handler(int sig)
{
	static int	ret;

	if (sig == SIGUSR1)
		ret++;
	else
	{
		ft_putstr_fd("Received: ", 1);
		ft_putnbr_fd(ret, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

void	ft_checker(int pid, char c, int i)
{
	unsigned char	bite;
	int				ans;

	bite = (c >> i & 1);
	if (bite == 0)
		ans = kill (pid, SIGUSR1);
	else
		ans = kill (pid, SIGUSR2);
	if (ans == -1)
	{
		ft_putstr_fd ("Error! Send message error.\n", 2);
		exit(1);
	}
	usleep(100);
}

void	ft_decoder(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
			ft_checker(pid, c, i);
	}
	i = 8;
	while (i--)
	{
		kill (pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	s_sigaction;

	if (argc < 3)
	{
		ft_putstr_fd ("Error! Expected 2 arguments.\n", 2);
		return (1);
	}
	ft_putstr_fd("Send   : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_handler = sig_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	ft_decoder(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
