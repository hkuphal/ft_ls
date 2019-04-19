/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:13:56 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/27 17:36:58 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long long	nb;
	long long	check;
	int			sign;

	nb = 0;
	check = 0;
	sign = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = 1;
	}
	while (*str >= '0' && *str <= '9')
	{
		check = nb;
		nb = nb * 10 + *str++ - '0';
		if (nb < check)
			return (sign == 1) ? (0) : (-1);
	}
	return (sign == 1) ? (-nb) : (nb);
}
