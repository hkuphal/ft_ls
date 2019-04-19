SRCL = ft_bzero.c ft_atoi.c ft_strlen.c ft_putstr.c ft_putchar.c ft_strnew.c\
ft_memmove.c ft_itoa.c ft_strncpy.c ft_strlen_chr.c ft_putstr_chr.c\
ft_strlen_chr.c ft_strrev.c ft_memset.c ft_strjoin.c ft_strcpy.c ft_strcat.c\
ft_strdup.c ft_itoa_base.c ft_itoa_u.c ft_reverse_bits.c ft_itoa_bin.c\
ft_itoa_pointer.c ft_itoa_double.c ft_strjoin_free.c ft_itoa_ldouble.c\
ft_strcmp.c ft_strncat.c ft_itoa_roundd.c
SRC = $(SRCL:%=../libft/%) ft_printf.c io.c init.c num.c str.c precision.c spec.c\
double.c
OBJ = $(SRC:.c=.o)
GCC = gcc -Werror -Wall -Wextra
INCS = -I libft/
NAME = libftprintf.a
PRINTF=printf $(VERBOSE)$(TRAVIS)

all:
	@$(PRINTF) "%-20s\r\033[0;33m$(NAME)\033[0m"
	$(MAKE) -q $(NAME) ; \
	if [ $$? -eq 0 ] ; then $(PRINTF) "\r\x1b[20C\x1b[0K\033[0;31m $(NAME) \
	is already up to date\033[0m\n"; \
	else $(MAKE) $(NAME) && $(PRINTF) "\r\x1b[20C\x1b[0K\033[0;32m✔\033[0m\n"; \
	fi


$(NAME): $(OBJ)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	@$(PRINTF) "\r\x1b[20C\x1b[0K$<"
	$(GCC) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

ifndef VERBOSE
 ifndef TRAVIS
.SILENT:
 endif
endif