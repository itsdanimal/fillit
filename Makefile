# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danli <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 13:43:06 by danli             #+#    #+#              #
#    Updated: 2019/11/13 16:45:53 by danli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =      main.c \
            grid.c \
            list.c \
            solver.c \
            valid.c
LIBFT = libft/
all: $(NAME)
$(NAME): 
	@make -C libft
	@$(CC) $(CFLAGS) $(SRC) libft/libft.a -o fillit
	@echo "Fillit Generation Complete"
clean:
	@make -C $(LIBFT) clean
fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a
	@make -C $(LIBFT) fclean
re: fclean all
