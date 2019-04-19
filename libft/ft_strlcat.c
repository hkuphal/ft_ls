/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:34:58 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/20 12:35:02 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dest_len;
	size_t src_len;
	size_t i;
	size_t all;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	all = dest_len + src_len;
	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	while ((i < size - dest_len - 1) && src_len--)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (all);
}
