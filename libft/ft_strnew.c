/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:22:50 by hkuphal           #+#    #+#             */
/*   Updated: 2019/01/26 10:18:31 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char			*str;
	char			*tmp;

	if ((str = (char *)malloc(sizeof(char) * size + 1)))
	{
		tmp = str;
		*str = '\0';
		while (size--)
			*(++str) = '\0';
		return (tmp);
	}
	return (NULL);
}
