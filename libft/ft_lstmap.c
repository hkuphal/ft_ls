/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:23:24 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/24 19:36:45 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *begin;

	if ((new = (t_list*)malloc(sizeof(t_list))) && lst)
	{
		new = f(lst);
		begin = new;
		while (lst->next)
		{
			new->next = (t_list*)malloc(sizeof(t_list));
			new->next = f(lst->next);
			new = new->next;
			lst = lst->next;
		}
		return (begin);
	}
	return (NULL);
}
