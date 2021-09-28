/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:41:40 by bpatrici          #+#    #+#             */
/*   Updated: 2021/05/11 13:42:58 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;
	size_t	s_len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen((char *)set);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s_len = ft_strlen((char *)s1);
	while (s_len && ft_strchr(set, s1[s_len]))
		s_len--;
	trim = ft_substr((char *)s1, 0, s_len + 1);
	return (trim);
}
