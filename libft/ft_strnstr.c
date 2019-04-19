/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:36:55 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/22 17:12:40 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmp;
	int		i;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && (len >= ft_strlen(needle)) && len--)
	{
		i = -1;
		tmp = (char*)haystack;
		while (needle[++i])
		{
			if (*(haystack + i) && needle[i] == *(haystack + i) &&
					needle[i + 1])
				continue;
			else if (needle[i] == *(haystack + i) && *(haystack + i))
				return (tmp);
			else
				break ;
		}
		haystack++;
	}
	return (NULL);
}
