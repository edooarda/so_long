# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: edribeir <edribeir@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/03/05 15:23:53 by edribeir      #+#    #+#                  #
#    Updated: 2024/03/20 15:56:36 by edribeir      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./Libft/libft.a

MLXLIB = MLX42/build/libmlx42.a

LIBMLX = ./MLX42

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

FLAGSMLX = -ldl -lglfw -pthread -lm 

SOURCE = so_long.c \
			parsing.c \
			checkers.c \
			str_map_checkers.c \

OBJECTS = $(SOURCE:%.c=%.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -DEBUG=1 -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@$(MAKE) -C ./Libft

	
$(NAME): $(LIBFT) $(MLXLIB) $(OBJECTS)
	@cc $(CFLAGS) $(FLAGSMLX) $(OBJECTS) $(LIBFT) $(MLXLIB) -o $(NAME)
	@echo "----> LET'S PLAY!! 🎉🎉"

%.o:%.c 
	@cc $(CFLAGS) -c -o $@ $^

clean: 
	@$(MAKE) clean -C ./Libft
	@rm -f $(OBJECTS)
	@rm -rf $(LIBMLX)/build
	@echo "------> OFILES Cleansed ✅!"

fclean: clean
	@$(MAKE) fclean -C $ ./Libft
	@rm -f $(NAME)
	@echo "------> ALL Cleansed ✅!"

re: fclean all

.PHONY: all clean fclean re 