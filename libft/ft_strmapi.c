/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:23:04 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/23 14:34:41 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	char				*tmp;
	int					len;
	unsigned int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if ((str = (char*)malloc(sizeof(char) * len + 1)))
	{
		tmp = str;
		while (*s)
			*str++ = (*f)(i++, *s++);
		*str = '\0';
		return (tmp);
	}
	return (NULL);
}
