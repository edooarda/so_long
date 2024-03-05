# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: edribeir <edribeir@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/20 13:36:22 by edribeir      #+#    #+#                  #
#    Updated: 2024/02/05 14:48:26 by edribeir      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar -rsc

INCLUDE = libft.h

SOURCE = ft_isdigit.c \
		ft_memset.c \
		ft_strlcpy.c \
		ft_substr.c \
		ft_atoi.c \
		ft_atol.c \
		ft_isprint.c \
		ft_split.c \
		ft_strlen.c	\
		ft_tolower.c \
		ft_bzero.c \
		ft_itoa.c \
		ft_strchr.c \
		ft_strmapi.c \
		ft_toupper.c \
		ft_calloc.c \
		ft_memchr.c \
		ft_strdup.c \
		ft_strncmp.c \
		ft_isalnum.c \
		ft_memcmp.c \
		ft_striteri.c \
		ft_strnstr.c \
		ft_isalpha.c \
		ft_memcpy.c \
		ft_strjoin.c \
		ft_strrchr.c \
		ft_isascii.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_printf.c \
		ft_print_hex.c \
		ft_source.c \
		get_next_line.c \
		get_next_line_utils.c \
		# ft_lstnew.c \
		# ft_lstadd_front.c \
		# ft_lstsize.c \
		# ft_lstlast.c \
		# ft_lstadd_back.c \
		# ft_lstdelone.c \
		# ft_lstclear.c \
		# ft_lstiter.c \
		# ft_lstmap.c \

OBJECTS = $(SOURCE:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o:%.c $(CC) -c $(CFLAGS) -o $@ $^

clean: 
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
