/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:21:43 by danli             #+#    #+#             */
/*   Updated: 2019/11/13 17:41:03 by danli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_list	*tetrilist;
	char	**grid;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fillit source_file\n");
		return (1);
	}
	if ((tetrilist = checker(av[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	grid = ft_solver(tetrilist);
	print_grid(grid);
	return (0);
}
