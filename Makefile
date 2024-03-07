# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: edribeir <edribeir@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/03/05 15:23:53 by edribeir      #+#    #+#                  #
#    Updated: 2024/03/07 14:21:39 by edribeir      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./Libft/libft.a

MLXLIB = MLX42/build/libmlx42.a

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

FLAGS = -ldl -lglfw -pthread -lm

SOURCE = so_long.c \

OBJECTS = $(SOURCE:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./Libft

	
$(NAME): $(LIBFT) $(MLXLIB) $(OBJECTS)
	@cc $(CFLAGS) $(FLAGS) $(OBJECTS) $(LIBFT) $(MLXLIB) -o $(NAME)
	@echo "----> LET'S PLAY!! 🎉🎉"

%.o:%.c 
	@cc $(CFLAGS) -c -o $@ $^

clean: 
	@$(MAKE) clean -C ./Libft
	@rm -f $(OBJECTS)
	@echo "------> OFILES Cleansed ✅!"

fclean: clean
	@$(MAKE) fclean -C $ ./Libft
	@rm -f $(NAME)
	@echo "------> ALL Cleansed ✅!"

re: fclean all

.PHONY: all clean fclean re 