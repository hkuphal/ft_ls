SRCL = ft_bzero.c ft_atoi.c ft_strlen.c ft_putstr.c ft_putchar.c ft_strnew.c\
ft_memmove.c ft_itoa.c ft_strncpy.c ft_strlen_chr.c ft_putstr_chr.c\
ft_strlen_chr.c ft_strrev.c ft_memset.c ft_strjoin.c ft_strcpy.c ft_strcat.c\
ft_strdup.c ft_itoa_base.c ft_itoa_u.c ft_reverse_bits.c ft_itoa_bin.c\
ft_itoa_pointer.c ft_itoa_double.c ft_strjoin_free.c ft_itoa_ldouble.c\
ft_strcmp.c ft_strncat.c ft_itoa_roundd.c
SRC = $(SRCL:%=../libft/%) ft_printf.c io.c init.c num.c str.c precision.c spec.c\
double.c
OBJ = $(SRC:.c=.o)
FLAGS = -Werror -Wall -Wextra
INCS = #-I libft/
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	gcc $(FLAGS) $(INCS) -c $< -o $@

clean:
	make clean -C ../libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ../libft/
	rm -f $(NAME)

re: fclean all
