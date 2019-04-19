# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 16:55:32 by ghalvors          #+#    #+#              #
#    Updated: 2019/04/19 18:50:56 by ghalvors         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
GCC = gcc -Wall -Wextra -Werror
SRCDIR = src
OBJDIR = obj
SRC := $(shell find $(SRCDIR) -type f -name '*.c')
OBJECTS := $(patsubst src/%,obj/%,$(SRC:%.c=%.o))
INCLUDESDIR = includes
LIB_DIR = libft
PRINTF_DIR = ft_printf
HEADER = includes/ft_ls.h libft/libft.h ft_printf/ft_printf.h
SUBDIRS = ft_printf libft
LIB_INC = -Llibft -lft -lm
PRINTF_INC = -Lft_printf -lftprintf
PRINTF = test $(VERBOSE)$(TRAVIS) || printf

.PHONY: all

all: libraries
	@$(PRINTF) "\r\033[0;36mCompiling main program\n"
	@$(PRINTF) "%-20s\r\033[0;36m$(NAME)\033[0m"
	$(MAKE) -q $(NAME) ; \
	if [ $$? -eq 0 ] ; then $(PRINTF) "\r\x1b[20C\x1b[0K\033[0;31m $(NAME) \
	is already up to date\033[0m\n"; \
	else $(MAKE) $(NAME) && $(PRINTF) "\r\x1b[20C\x1b[0K\033[0;32m✔\033[0m\n"; \
	fi
	@$(PRINTF) "\r\033[0;35mProgram compiled succesfuly\n"


$(NAME): $(OBJECTS)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	$(GCC) $(LIB_INC)  $(PRINTF_INC) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADER)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	$(GCC) -I $(INCLUDESDIR) -I $(LIB_DIR) -I $(PRINTF_DIR) -c $< -o $@

libraries:
	@$(PRINTF) "\r\033[0;32mCompiling external libraries\033[0m\n"
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	rm -rf $(OBJECTS)
	@for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
	done

fclean: clean
	rm -rf $(NAME)
	@for dir in $(SUBDIRS); do \
		$(MAKE) fclean -C $$dir; \
	done

re: fclean all

.PHONY: all clean fclean re

ifndef VERBOSE
 ifndef TRAVIS
.SILENT:
 endif
endif
