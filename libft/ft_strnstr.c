/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:43:26 by bpatrici          #+#    #+#             */
/*   Updated: 2021/05/11 12:47:49 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr (const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;
	size_t	j;

	i = 0;
	n_len = ft_strlen((char *)needle);
	if (n_len == 0)
		return ((char *) haystack);
	while (haystack[i] != '\0' && i <= len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *) haystack + i);
			}
		}
		i++;
	}
	return (0);
}
