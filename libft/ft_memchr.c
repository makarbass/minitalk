/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:00:47 by bpatrici          #+#    #+#             */
/*   Updated: 2021/05/11 15:51:19 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*st;
	unsigned char	ch;

	st = (unsigned char *)arr;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*st == ch)
			return (st);
		st++;
	}
	return (NULL);
}
