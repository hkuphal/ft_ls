/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:33:54 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/23 13:31:27 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if ((unsigned char*)dst > (unsigned char*)src && len)
	{
		while (--len > 0)
			*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
		*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
	}
	else
		while (i < len)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i++;
		}
	return (dst);
}
