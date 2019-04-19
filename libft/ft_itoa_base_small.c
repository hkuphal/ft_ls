/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_small.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:52:49 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/14 17:07:03 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*check_value(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char))))
		return (NULL);
	str[0] = '0';
	return (str);
}

static void	get_len(int *len, long *nbr, int base)
{
	int		value;

	value = *nbr;
	while (*nbr)
	{
		*nbr /= base;
		*len += 1;
	}
	*nbr = value;
	if (*nbr < 0)
	{
		if (base == 10)
			*len += 1;
		*nbr *= -1;
	}
}

char		*ft_itoa_base_small(int value, int base)
{
	int		len;
	long	nbr;
	char	*str;
	char	*base_string;

	base_string = "0123456789abcdef";
	if (value == 0)
		return (check_value());
	len = 0;
	nbr = value;
	get_len(&len, &nbr, base);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (nbr)
	{
		str[--len] = base_string[nbr % base];
		nbr /= base;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
