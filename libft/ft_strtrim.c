/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:41:10 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/23 13:48:48 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int	get_len(char const *s, int start)
{
	int		i;
	int		len;

	len = 0;
	i = (int)ft_strlen(s);
	while (is_space(s[--i]))
		;
	i++;
	while (i-- > start)
		len++;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		start;

	if (s != NULL)
	{
		if (is_space(*s) || is_space(*(s + ft_strlen(s) - 1)))
		{
			start = -1;
			while (is_space(s[++start]))
				;
			len = get_len(s, start);
			if ((str = (char*)malloc(sizeof(char) * len + 1)))
			{
				ft_strncpy(str, s + start, len);
				str[len] = '\0';
				return (str);
			}
			return (NULL);
		}
		return (ft_strdup(s));
	}
	return (NULL);
}
