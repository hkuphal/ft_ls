# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkuphal <hkuphal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 17:23:25 by hkuphal           #+#    #+#              #
#    Updated: 2019/04/19 18:07:05 by hkuphal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_ls.c init.c reader.c
OBJ = $(SRC:.c=.o)
NAME = ft_ls
FLAGS = -Werror -Wall -Wextra
INCS = #-I libft/ -I ft_printf/
LIBS = -L libft/ -L ft_printf/ -lft -lftprintf

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C ft_printf/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o : %.c ft_ls.h
	gcc $(FLAGS) -c $< $(INCS)

clean:
	rm -f $(OBJ)
	make -C libft/ clean
	make -C ft_printf/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C ft_printf/ fclean

re: fclean all
