/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:07:07 by bpatrici          #+#    #+#             */
/*   Updated: 2021/05/11 13:41:34 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	i;
	char	*s;
	int		j;

	j = 0;
	i = (char)ch;
	s = (char *)str;
	while (s[j])
		j++;
	while (j > -1)
	{
		if (s[j] == i)
			return (&s[j]);
		j--;
	}
	return (NULL);
}
