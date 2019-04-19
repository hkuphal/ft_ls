/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:18:47 by hkuphal           #+#    #+#             */
/*   Updated: 2019/01/26 10:18:48 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		begin;
	int		end;
	int		len;
	char	tmp;

	begin = -1;
	end = ft_strlen(str) - 1;
	len = end / 2;
	while (++begin < len)
	{
		tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		end--;
	}
	return (str);
}
