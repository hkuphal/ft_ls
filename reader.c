/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <hkuphal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:45:38 by hkuphal           #+#    #+#             */
/*   Updated: 2019/04/19 18:51:16 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		choose_flag(t_gen *gen, char *flag)
{
	if (!ft_strcmp(flag, "-l"))
		return (gen->flags |= 1);
	else if (!ft_strcmp(flag, "-R"))
		return (gen->flags |= 2);
	else if (!ft_strcmp(flag, "-a"))
		return (gen->flags |= 4);
	else if (!ft_strcmp(flag, "-r"))
		return (gen->flags |= 8);
	else if (!ft_strcmp(flag, "-t"))
		return (gen->flags |= 16);
	else
		return (0);
}

void	reader(int ac, char **av, t_gen *gen)
{
	int		i;

	i = 0;
	while (++i < ac && av[i][0] == '-')
	{
		
		if (!choose_flag(gen, av[i]))
			break ;
	}
}