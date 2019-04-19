/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:10:41 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/23 14:33:55 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*tmp;
	int		len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if ((str = (char*)malloc(sizeof(char) * len + 1)))
	{
		tmp = str;
		while (*s)
			*str++ = (*f)(*s++);
		*str = '\0';
		return (tmp);
	}
	return (NULL);
}
