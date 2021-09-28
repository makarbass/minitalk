/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:36:19 by bpatrici          #+#    #+#             */
/*   Updated: 2021/09/28 13:36:21 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

void	sig_handler(int sig)
{
	(void)sig;
	usleep(50);
}

void	applying_bite_mask(int pid, char *str, int i, int counter_bite)
{
	unsigned char	bite_shift;
	int ans;

	bite_shift = (str[i] >> counter_bite) & 1;
	if (bite_shift == 0)
		ans = kill (pid, SIGUSR1);
	else
		ans = kill (pid, SIGUSR2);
	if (ans == -1)
	{
		ft_putstr_fd ("Error! Send message error.\n", 2);
		exit(0);
	}
	pause();
}

void	decoder(char *str, int pid)
{
	int	i;
	int	counter_bite;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (len--)
	{
		counter_bite = 0;
		while (counter_bite < 8)
			applying_bite_mask (pid, str, i, counter_bite++);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill (pid, SIGUSR1);
		pause();
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc < 3)
	{
		ft_putstr_fd ("Error! Expected 2 arguments.\n", 2);
		return (0);
	}
	
	signal(SIGUSR1, sig_handler);
	pid = ft_atoi(argv[1]);
	decoder(argv[2], pid);
	return (0);
}