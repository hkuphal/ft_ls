/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:26:15 by hkuphal           #+#    #+#             */
/*   Updated: 2019/04/19 18:54:26 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define DB(x) ((double)x)
# define FLAG_NUM 5

typedef struct		s_entity
{
	int				id;
	char			*name;
}					t_entity;


typedef struct		s_gen
{
	int				flags;
	struct s_entity	*entity;
}					t_gen;

void	init(t_gen *gen);
void	reader(int ac, char **av, t_gen *gen);

#endif
