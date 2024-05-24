# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: edribeir <edribeir@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/03/05 15:23:53 by edribeir      #+#    #+#                  #
#    Updated: 2024/05/24 17:03:46 by eduarda       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS_PART = so_long_bonus

LIBFT = ./Libft/libft.a

SUB = .MLX42

MLXLIB = MLX42/build/libmlx42.a

LIBMLX = ./MLX42

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

FLAGSMLX = -ldl -lglfw -pthread -lm 

SOURCE = main.c \
			parsing.c \
			str_map_checkers.c \
			array_map_checkers.c \
			content.c \
			texture_functions.c \
			add_to_window.c \
			movements.c \
			end_game_checkers.c \
			map_path_checker.c \

BONUS_SRC = ./bonus/main_bonus.c \
			./bonus/parsing_bonus.c \
			./bonus/str_map_checkers_bonus.c \
			./bonus/array_map_checkers_bonus.c \
			./bonus/content_bonus.c \
			./bonus/texture_functions_bonus.c \
			./bonus/player_sprites_bonus.c \
			./bonus/add_to_window_bonus.c \
			./bonus/movements_bonus.c \
			./bonus/end_game_checkers_bonus.c \
			./bonus/map_path_checker_bonus.c \
			./bonus/message_window_bonus.c \
			./bonus/enemies_bonus.c \

OBJECTS = $(SOURCE:%.c=%.o)

BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

all: $(SUB) $(MLXLIB) $(NAME)

bonus: $(BONUS_PART)

$(SUB):
	@echo "\t\tUpdating submodules...⌛"
	@git submodule update --init --recursive
	@echo "\t\tSubmodules Updated ✅"

$(MLXLIB):
	@cmake $(LIBMLX) -DEBUG=1 -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@$(MAKE) -C ./Libft

$(NAME): $(LIBFT) $(MLXLIB) $(OBJECTS)
	@cc $(CFLAGS) $(FLAGSMLX) $(OBJECTS) $(LIBFT) $(MLXLIB) -o $(NAME)
	@echo "\n\t LET'S PLAY!! 🎉🎉\n"

%.o:%.c 
	@cc $(CFLAGS) -c -o $@ $^

%.o:%./bonus/.c 
	@cc $(CFLAGS) -c -o $@ $^

$(BONUS_PART): $(LIBFT) $(MLXLIB) $(BONUS_OBJ)
	@cc $(CFLAGS) $(FLAGSMLX) $(BONUS_OBJ) $(LIBFT) $(MLXLIB) -o $(BONUS_PART)
	@echo "\tB\tO\tN\tU\tS 🌟"
	@echo "\t LOOK AT THE WATER! It is Enemy!"

clean: 
	@$(MAKE) clean -C ./Libft
	@rm -f $(OBJECTS)
	@echo "\t OFILES Cleansed ✅!"

fclean: clean
	@$(MAKE) fclean -C $ ./Libft
	@rm -f $(NAME)
	@rm -rf $(LIBMLX)/build
	@rm -f $(BONUS_OBJ)
	@rm -f $(BONUS_PART)
	@echo "\t ALL Cleansed ✅!"

re: fclean all

.PHONY: all clean fclean re bonus