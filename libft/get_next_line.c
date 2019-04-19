/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:00:18 by hkuphal           #+#    #+#             */
/*   Updated: 2018/12/06 17:46:09 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_charjoin(char **s1, t_lst *lst, int len1, int len2)
{
	char			*temp;
	int				i;

	i = 0;
	if (!(temp = (char*)malloc(sizeof(char) * (len1 + len2) + 1)))
		return (0);
	while (i < len1)
	{
		temp[i] = (*s1)[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		temp[len1 + i] = lst->cont[lst->pos + i];
		i++;
	}
	free(*s1);
	temp[len1 + len2] = '\0';
	*s1 = temp;
	return (1);
}

t_lst	*init_lst(int fd)
{
	t_lst			*lst;
	int				i;

	i = -1;
	lst = NULL;
	if ((lst = (t_lst*)malloc(sizeof(t_lst) * 1)))
	{
		while (++i < BUFF_SIZE)
			lst->cont[i] = '\0';
		if ((lst->len = read(fd, lst->cont, BUFF_SIZE)) < 0)
			return (NULL);
		lst->fd = fd;
		lst->pos = 0;
		lst->next = NULL;
		return (lst);
	}
	return (NULL);
}

int		add_next_line(t_lst **lst, char **line)
{
	int				i;
	int				full;

	full = 0;
	while ((*lst)->len)
	{
		i = (*lst)->pos;
		while ((*lst)->cont[i] != '\n' && i < (*lst)->len)
			i++;
		if (!ft_charjoin(line, (*lst), full, i - (*lst)->pos))
			return (-1);
		full += (i - (*lst)->pos);
		(*lst)->pos = (i == (*lst)->len) ? (i - 1) : (i);
		if ((*lst)->cont[(*lst)->pos] != '\n')
		{
			(*lst)->pos = 0;
			if (((*lst)->len = read((*lst)->fd, (*lst)->cont, BUFF_SIZE)) < 0)
				return (-1);
		}
		else
			return (check_next_line(lst, line));
	}
	return (1);
}

int		check_next_line(t_lst **lst, char **line)
{
	if ((*lst)->len == 0)
	{
		if (((*lst)->len = read((*lst)->fd, (*lst)->cont, BUFF_SIZE)) < 0)
			return (-1);
		return ((*lst)->len == 0) ? (0) : (add_next_line(lst, line));
	}
	if ((*lst)->cont[(*lst)->pos] == '\n')
	{
		if ((*lst)->pos + 1 == BUFF_SIZE)
		{
			(*lst)->pos = 0;
			if (((*lst)->len = read((*lst)->fd, (*lst)->cont, BUFF_SIZE)) < 0)
				return (-1);
			return (1);
		}
		((*lst)->pos)++;
		if ((*lst)->pos == (*lst)->len)
		{
			(*lst)->pos = 0;
			(*lst)->len = 0;
		}
		return (1);
	}
	return (add_next_line(lst, line));
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*lst;
	t_lst			*curr;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	if (!(*line = (char*)malloc(sizeof(char) * 1)))
		return (-1);
	*line[0] = '\0';
	if (!lst && !(lst = init_lst(fd)))
		return (-1);
	else
	{
		curr = lst;
		while (curr && curr->fd != fd)
		{
			if (!curr->next && !(curr->next = init_lst(fd)))
				return (-1);
			curr = curr->next;
		}
		return (check_next_line(&curr, line));
	}
}
