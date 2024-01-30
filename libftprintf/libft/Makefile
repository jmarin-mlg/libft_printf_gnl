# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 17:52:26 by jmarin-o          #+#    #+#              #
#    Updated: 2024/01/30 18:11:24 by jmarin-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM NAME
NAME = libft.a

# SOURCES
SOURCES = 	ft_atoi.c 		\
			ft_bzero.c 		\
			ft_calloc.c 	\
			ft_isalnum.c 	\
			ft_isalpha.c 	\
			ft_isascii.c 	\
			ft_isdigit.c 	\
			ft_isprint.c 	\
			ft_itoa.c 		\
			ft_memchr.c 	\
			ft_memcmp.c 	\
			ft_memcpy.c 	\
			ft_memmove.c 	\
			ft_memset.c 	\
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c 	\
			ft_putstr_fd.c 	\
			ft_split.c 		\
			ft_strchr.c 	\
			ft_strdup.c 	\
			ft_striteri.c 	\
			ft_strjoin.c 	\
			ft_strlcat.c 	\
			ft_strlcpy.c 	\
			ft_strlen.c 	\
			ft_strmapi.c 	\
			ft_strncmp.c 	\
			ft_strnstr.c 	\
			ft_strrchr.c 	\
			ft_strtrim.c 	\
			ft_substr.c 	\
			ft_tolower.c 	\
			ft_toupper.c

BONUS_SOURCES = ft_lstadd_back_bonus.c  \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c 	\
				ft_lstdelone_bonus.c 	\
				ft_lstiter_bonus.c 		\
				ft_lstlast_bonus.c 		\
				ft_lstmap_bonus.c 		\
				ft_lstnew_bonus.c 		\
				ft_lstsize_bonus.c

# FLAGS
FLAGS = -Wall -Wextra -Werror

# OBJECTS
OBJS       = ${SOURCES:.c=.o}
BONUS_OBJS = ${BONUS_SOURCES:.c=.o}

# RULES
all: ${NAME}

${NAME}: ${OBJS}
	@ar -rcus $@ $^

bonus: ${BONUS_OBJS}
	@ar -rcus ${NAME} $^

%.o: %.c
	@cc ${FLAGS} -c -o $@ $^

clean:
	@rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus

# ADDITIONAL INFORMATION

# Use of `$@` and `$^`
#	$@: The $@ symbol is used to suppress the echoing of the command being
#	executed. When a command in a Makefile is prefixed with @, it prevents make
#	from printing the command to the standard output. It is often used to make
#	the output more concise and focused on the results rather than the individual
#	commands.

#	$^: The $^ is a special automatic variable in make that represents the list
#	of all the prerequisites (dependencies) of a rule. It is often used within
#	the commands of a rule to refer to all the dependencies.

#	Example (print "Building target from dependency1 dependency2"):
#		target: dependency1 dependency2
#			@echo "Building $@ from $^"

# AR command flags
#	-r (replace): This flag indicates to ar that it should replace existing
#	files in the archive. If a file with the same name already exists in the
#	archive, it will be replaced or updated with the new file. If the file
#	doesn't exist, a new one will be added.

#	-c (create): Create the library if it does not exist.

#	-u (update): The -u flag tells ar to update only those files that have
#	changed since they were last added to the archive. This means that only
#	the modified object files will be added or replaced in the archive.

#	-s (index): This flag ensures that an index is created or updated in the
#	archive. An index can improve the performance of certain link operations.

#	-v (verbose): The -v flag stands for "verbose" and it makes the ar command
#	print details about the files being added or replaced. It shows the names of
#	the files as they are processed.
