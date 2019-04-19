# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 16:12:12 by hkuphal           #+#    #+#              #
#    Updated: 2019/02/22 12:06:06 by hkuphal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c ft_memset.c\
ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c\
ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strncmp.c ft_atoi.c\
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c\
ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putnbr.c ft_itoa.c\
ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
ft_sqrt_n.c ft_memjoin.c get_next_line.c ft_strlen_chr.c ft_putstr_chr.c\
ft_strrev.c ft_count_words.c ft_itoa_base.c ft_itoa_u.c ft_reverse_bits.c\
ft_itoa_bin.c ft_itoa_pointer.c ft_itoa_double.c ft_strjoin_free.c\
ft_itoa_ldouble.c ft_itoa_roundd.c ft_atoi_long.c
OBJ = $(SRC:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	gcc -c -Werror -Wall -Wextra -I. -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	gcc -c $(FLAGS) -fpic $(SRC)
	gcc -shared -o libft.so $(OBJ)
