/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:12:36 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/20 17:20:25 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	if ((tmp = (unsigned char*)malloc(sizeof(size_t) * size)) && size != 0)
	{
		i = 0;
		while (i < size)
		{
			tmp[i] = 0;
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
