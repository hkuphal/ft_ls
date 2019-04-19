/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:25:01 by hkuphal           #+#    #+#             */
/*   Updated: 2018/12/24 17:25:02 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memjoin(void **dst, const void *src, size_t l1, size_t l2)
{
	unsigned char	*tmp;
	unsigned char	**dst_tmp;
	size_t			i;

	dst_tmp = (unsigned char**)dst;
	i = 0;
	if (!(tmp = (unsigned char*)malloc(sizeof(unsigned char) * (l1 + l2) + 1)))
		return (0);
	while (i < l1)
	{
		tmp[i] = (*dst_tmp)[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		tmp[l1 + i] = ((unsigned char*)src)[i];
		i++;
	}
	free(*dst);
	tmp[l1 + l2] = '\0';
	*dst = tmp;
	return (1);
}
