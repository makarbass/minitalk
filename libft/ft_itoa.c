/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:34:49 by bpatrici          #+#    #+#             */
/*   Updated: 2021/05/12 18:28:54 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_del(int n)
{
	int		d;

	d = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		++d;
	}
	return (d);
}

static char	*ft_plus_int(int n, int len)
{
	char	*ss;

	ss = (char *)malloc(sizeof(*ss) * (len + 1));
	if (!ss)
		return (NULL);
	else
	{
		ss[len] = '\0';
		len--;
		while (len >= 0)
		{
			ss[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (ss);
	}
}

static char	*ft_mius_int(int n, int len)
{
	char	*ss;

	ss = (char *)malloc(sizeof(*ss) * (len + 2));
	if (!ss)
		return (NULL);
	else
	{
		len++;
		ss[len] = '\0';
		len--;
		ss[0] = '-';
		while (len > 0)
		{
			ss[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (ss);
	}
}

char	*ft_itoa(int n)
{
	char	*ss;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbr_del(n);
	if (n >= 0)
		return (ss = ft_plus_int(n, len));
	return (ss = ft_mius_int((n * -1), len));
}
