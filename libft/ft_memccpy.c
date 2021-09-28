/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:35:53 by bpatrici          #+#    #+#             */
/*   Updated: 2021/05/11 12:39:15 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy (void *destination, const void *source, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
		if (s[i - 1] == (unsigned char)c)
			return (&d[i]);
	}
	return ((void *) 0);
}
