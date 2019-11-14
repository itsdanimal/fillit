/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:50:52 by danli             #+#    #+#             */
/*   Updated: 2019/11/13 17:42:13 by danli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFF_SIZE 545
# define FILLIT_MACRO int x; int y; int i; int num;

typedef struct		s_etris
{
	int				x_coord[4];
	int				y_coord[4];
	int				x_offset;
	int				y_offset;
	char			letter;
	struct e_list	*next;
}					t_etris;

t_list				*checker(char *file);
int					valid(char *buff);
int					is_block(char *buff);
t_list				*make_list(char *buff);
void				ft_coord(t_etris *coord, char *buff, char letter);
void				ft_shifter(t_etris *coord);
char				**ft_solver(t_list *tetrilist);
int					solve_fillit(t_list *tetrilist, char **grid, int grid_size);
int					boundaries(t_etris *tetri, int grid_size, char axis);
int					overlap(t_etris *tetri, char **grid);
void				place(t_etris *tetri, char **grid, char letter);
char				**grid_size(t_list *tetrilist, int i);
int					ft_countlist(t_list *tetrilist);
void				print_grid(char **grid);

#endif
