# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 06:31:19 by jmarin-o          #+#    #+#              #
#    Updated: 2024/01/24 19:17:24 by jmarin-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus make_libft clean fclean re

# PROGRAMS NAME
NAME       = libftprintf.a
NAME_LIBFT = libft.a
DIR_LIBFT  = ../libft

## SOURCES
SOURCES = 	ft_printf.c               \
			ft_print_data.c           \
			ft_print_character.c      \
			ft_print_string.c         \
			ft_print_pointer.c 		  \
			ft_print_number.c 		  \
		 	ft_print_hexadecimal.c    \
		 	init_functions.c 		  \
		 	util_print_functions_01.c \
		 	util_print_functions_02.c

SOURCES_BONUS =	ft_printf_bonus.c               \
				ft_print_data_bonus.c           \
				ft_print_character_bonus.c      \
				ft_print_string_bonus.c         \
				ft_print_pointer_bonus.c        \
		 		ft_print_number_bonus.c         \
		 		ft_print_hexadecimal_bonus.c    \
				init_functions_bonus.c          \
				util_print_functions_01_bonus.c \
				util_print_functions_02_bonus.c

## OBJECTS
OBJS       = $(SOURCES:.c=.o)
OBJS_BONUS = $(SOURCES_BONUS:.c=.o)

## COMPILER AND FLAGS
CC     = @gcc
CFLAGS = -Wall -Wextra -Werror

## RULES
all: $(NAME)

$(NAME): make_libft $(OBJS)
	@ar -rcusv $(NAME) $(OBJS)

bonus: make_libft $(OBJS_BONUS)
	@ar -rcusv $(NAME) $(OBJS_BONUS)

make_libft:
	make -C $(DIR_LIBFT)
	@cp $(DIR_LIBFT)/$(NAME_LIBFT) $(NAME)

clean:
ifneq ("$(wildcard $(OBJS) $(OBJS_BONUS))", "")
	make -C $(DIR_LIBFT) clean
	@rm -f $(OBJS) $(OBJS_BONUS)
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	make -C $(DIR_LIBFT) fclean
	@rm -f $(NAME)
endif

re: fclean all
