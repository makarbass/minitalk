/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:46:57 by bpatrici          #+#    #+#             */
/*   Updated: 2021/09/24 13:49:50 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/libft.h"
typedef struct s_data
{
	char	simbol;
	int		position_digit;
	int		error_flag;
}				t_data;

#endif


