/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:06:37 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/22 12:19:04 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi_long(const char *str)
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
