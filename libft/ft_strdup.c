/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:34:52 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/20 12:34:53 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	len = -1;
	while (s[++len])
		;
	if ((str = (char *)malloc(sizeof(char) * len + 1)))
	{
		len = -1;
		while (s[++len])
			str[len] = s[len];
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
