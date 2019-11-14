/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:21:07 by danli             #+#    #+#             */
/*   Updated: 2019/11/13 16:19:16 by danli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_grid(char **grid)
{
	int x;
	int y;
	int count;

	count = ft_strlen(*grid);
	x = -1;
	while (++x < count)
	{
		y = 0;
		while (y < count)
			ft_putchar(grid[x][y++]);
		if (y == count)
			ft_putchar('\n');
	}
}

char	**grid_size(t_list *tetrilist, int n)
{
	char **grid;

	FILLIT_MACRO;
	i = 2;
	num = ft_lstcount(tetrilist);
	num = num * 4;
	while (i * i < num)
		i++;
	if (!(grid = (char**)ft_memalloc(sizeof(*grid) * (((i + n) + 1)))))
		return (NULL);
	y = -1;
	while (++y < (i + n))
		if (!(grid[y] = (char*)ft_memalloc(sizeof(char) * ((i + n) + 1))))
			return (NULL);
	y = -1;
	while (++y < (i + n))
	{
		x = -1;
		while (++x < (i + n))
			grid[y][x] = '.';
	}
	return (grid);
}
