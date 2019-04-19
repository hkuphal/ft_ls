/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:33:18 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/22 13:46:50 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *temp;

	temp = dst;
	while (n--)
	{
		*temp++ = *(unsigned char*)src++;
		if (*((unsigned char*)src - 1) == (unsigned char)c)
			return (temp);
	}
	return (NULL);
}
