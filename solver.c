/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:22:35 by danli             #+#    #+#             */
/*   Updated: 2019/11/13 17:36:01 by danli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		boundaries(t_etris *tetri, int grid_size, char axis)
{
	if (axis == 'y')
	{
		return (tetri->y_coord[0] + tetri->y_offset < grid_size &&
				tetri->y_coord[1] + tetri->y_offset < grid_size &&
				tetri->y_coord[2] + tetri->y_offset < grid_size &&
				tetri->y_coord[3] + tetri->y_offset < grid_size);
	}
	else
	{
		return (tetri->x_coord[0] + tetri->x_offset < grid_size &&
				tetri->x_coord[1] + tetri->x_offset < grid_size &&
				tetri->x_coord[2] + tetri->x_offset < grid_size &&
				tetri->x_coord[3] + tetri->x_offset < grid_size);
	}
}

int		overlap(t_etris *tetri, char **grid)
{
	int i;
	int x;
	int y;

	i = 0;
	x = tetri->x_coord[i] + tetri->x_offset;
	y = tetri->y_coord[i] + tetri->y_offset;
	while (i < 4 && grid[y][x] == '.')
	{
		i++;
		x = tetri->x_coord[i] + tetri->x_offset;
		y = tetri->y_coord[i] + tetri->y_offset;
	}
	return (i != 4);
}

void	place(t_etris *tetri, char **grid, char letter)
{
	int i;
	int x;
	int y;

	i = -1;
	x = 0;
	y = 0;
	while (++i < 4)
	{
		x = tetri->x_coord[i] + tetri->x_offset;
		y = tetri->y_coord[i] + tetri->y_offset;
		grid[y][x] = letter;
	}
}

int		solve_fillit(t_list *tetrilist, char **grid, int grid_size)
{
	t_etris *tetri;

	if (!tetrilist)
		return (1);
	tetri = (t_etris*)(tetrilist->content);
	tetri->x_offset = 0;
	tetri->y_offset = 0;
	while (boundaries(tetri, grid_size, 'y'))
	{
		while (boundaries(tetri, grid_size, 'x'))
		{
			if (!overlap(tetri, grid))
			{
				place(tetri, grid, tetri->letter);
				if (solve_fillit(tetrilist->next, grid, grid_size))
					return (1);
				else
					place(tetri, grid, '.');
			}
			tetri->x_offset++;
		}
		tetri->x_offset = 0;
		tetri->y_offset++;
	}
	return (0);
}

char	**ft_solver(t_list *tetrilist)
{
	int		x;
	int		i;
	char	**grid;

	i = 0;
	x = 0;
	grid = grid_size(tetrilist, 0);
	while (solve_fillit(tetrilist, grid, ft_strlen(*grid)) == 0)
	{
		while (grid[x])
			free(grid[x++]);
		x = 0;
		grid = grid_size(tetrilist, ++i);
	}
	return (grid);
}
