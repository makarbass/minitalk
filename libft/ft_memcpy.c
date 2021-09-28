/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:12:58 by bpatrici          #+#    #+#             */
/*   Updated: 2021/05/11 12:49:00 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dest;
	s = src;
	i = 0;
	if (src != 0 || dest != 0)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (d);
	}
	return (0);
}
