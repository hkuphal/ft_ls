/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:43:25 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/20 14:10:39 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*tmp;
	int		i;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
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
