/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:49:25 by hkuphal           #+#    #+#             */
/*   Updated: 2019/04/19 18:54:21 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"

int		main(int ac, char **av)
{
	t_gen		gen;
	// struct stat	buff;

	init(&gen);
	reader(ac, av, &gen);
	ft_printf("%b\n", gen.flags);
	// stat(av[0], &buff);
	// ft_printf("%d\n", buff.st_size);
	return (0);
}
