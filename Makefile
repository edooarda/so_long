# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: edribeir <edribeir@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/03/05 15:23:53 by edribeir      #+#    #+#                  #
#    Updated: 2024/03/05 15:33:24 by edribeir      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = Libft/libft.a

LIBFTDIR = Libft

CC = cc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

RM = rm -f

SOURCE = 

OBJECTS = $(SOURCE:%.c=%.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
	
$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o:%.c 
	$(CC) $(CFLAGS) -c -o $@ $^ -I $(LIBFTDIR)
clean: 
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 