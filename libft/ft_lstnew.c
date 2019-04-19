/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:40:31 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/27 17:48:07 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	if ((new_list = (t_list*)malloc(sizeof(t_list))))
	{
		new_list->next = NULL;
		if (content == NULL)
		{
			new_list->content = NULL;
			content_size = 0;
			return (new_list);
		}
		new_list->content = (void*)ft_strdup(content);
		new_list->content_size = content_size;
		return (new_list);
	}
	return (NULL);
}
