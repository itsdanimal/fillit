/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:22:08 by danli             #+#    #+#             */
/*   Updated: 2019/11/13 16:21:01 by danli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_block(char *buff)
{
	FILLIT_MACRO;
	x = 0;
	y = 0;
	while (buff[x])
	{
		i = -1;
		num = 0;
		while (++i < 21)
		{
			if (buff[x] == '#' && buff[x + 5] == '#')
				num++;
			if (buff[x] == '#' && buff[x - 5] == '#')
				num++;
			if (buff[x] == '#' && buff[x + 1] == '#')
				num++;
			if (buff[x] == '#' && buff[x - 1] == '#')
				num++;
			x++;
		}
		if (!(num >= 6))
			return (1);
	}
	return (0);
}

int		valid(char *buff)
{
	FILLIT_MACRO;
	x = 0;
	y = 1;
	while (buff[x])
	{
		i = -1;
		num = 0;
		while (++i < 19)
		{
			if (buff[x] != '\n' && buff[x] != '.' && buff[x] != '#')
				return (1);
			if (buff[x] == '#')
				num++;
			if (buff[x] == '\n' && ((x + y) % 5 != 0))
				return (2);
			x++;
		}
		if (num != 4)
			return (3);
		x += 2;
		y--;
	}
	if (is_block(buff) != 0)
		return (5);
	return (0);
}

t_list	*checker(char *file)
{
	int		fd;
	char	buff[BUFF_SIZE];
	int		i;

	fd = open(file, O_RDONLY);
	i = read(fd, buff, BUFF_SIZE);
	close(fd);
	if (i > 544 || i < 19 || i % 21 == 0)
		return (0);
	if (valid(buff) != 0)
		return (0);
	return (make_list(buff));
}
