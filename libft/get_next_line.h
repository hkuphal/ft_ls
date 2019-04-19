/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:03:11 by hkuphal           #+#    #+#             */
/*   Updated: 2018/12/06 17:46:42 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 100

typedef struct		s_lst
{
	int				fd;
	int				len;
	int				pos;
	char			cont[BUFF_SIZE];
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);
int					ft_charjoin(char **s1, t_lst *lst, int len1, int len2);
t_lst				*init_lst(int fd);
int					add_next_line(t_lst **lst, char **line);
int					check_next_line(t_lst **lst, char **line);

#endif
