/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:22:44 by danli             #+#    #+#             */
/*   Updated: 2019/11/13 16:18:40 by danli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_shifter(t_etris *coord)
{
	while (coord->x_coord[0] != 0 && \
			coord->x_coord[1] != 0 && \
			coord->x_coord[2] != 0 && \
			coord->x_coord[3] != 0)
	{
		coord->x_coord[0] += -1;
		coord->x_coord[1] += -1;
		coord->x_coord[2] += -1;
		coord->x_coord[3] += -1;
	}
	while (coord->y_coord[0] != 0 && \
			coord->y_coord[1] != 0 && \
			coord->y_coord[2] != 0 && \
			coord->y_coord[3] != 0)
	{
		coord->y_coord[0] += -1;
		coord->y_coord[1] += -1;
		coord->y_coord[2] += -1;
		coord->y_coord[3] += -1;
	}
}

void	ft_coord(t_etris *coord, char *buff, char letter)
{
	FILLIT_MACRO;
	i = 0;
	y = 0;
	x = 0;
	num = 0;
	while (i++ < 21)
	{
		if (buff[x] == '#')
		{
			x < 21 ? coord->x_coord[num] = x % 5 : 0;
			coord->y_coord[num++] = y;
		}
		i % 5 == 0 ? y++ : 0;
		x++;
	}
	coord->letter = letter;
}

t_list	*make_list(char *buff)
{
	char		letter;
	t_list		*list;
	t_etris		*coord;
	int			i;

	i = 0;
	letter = 'A';
	list = NULL;
	if (!(coord = (t_etris *)ft_memalloc(sizeof(*coord))))
		return (NULL);
	while (buff[i])
	{
		ft_coord(coord, buff + i, letter++);
		i += 21;
		ft_shifter(coord);
		ft_lstadd(&list, ft_lstnew(coord, sizeof(t_etris)));
	}
	ft_lstrev(&list);
	return (list);
}
