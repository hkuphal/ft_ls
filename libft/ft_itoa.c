/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:56:31 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/23 13:13:46 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_len(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	is_negative(char *str, int *n)
{
	if (*n == -2147483648)
	{
		ft_strncpy(str, "-2147483648", 12);
		return (1);
	}
	str[0] = '-';
	*n = -*n;
	return (1);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 0;
	len = get_len(n);
	if ((str = (char*)malloc(sizeof(char) * len + 1)))
	{
		if (n < 0)
			sign = is_negative(str, &n);
		if (n == -2147483648)
			return (str);
		str[len] = '\0';
		while (len--)
		{
			str[len] = '0' + n % 10;
			n = n / 10;
		}
		(sign == 1) ? str[0] = '-' : 1;
		return (str);
	}
	return (NULL);
}
