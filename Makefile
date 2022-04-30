# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 09:45:39 by msaouab           #+#    #+#              #
#    Updated: 2022/04/30 16:05:09 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRC =	src/main.c\
		src/move_with_keys.c\
		src/print_map.c\
		src/read_map.c\
		src/destroy_game.c\
		src/position_p.c\
		src/any_key.c\
		src/ft_free.c\
		utils/errors.c\
		utils/get_next_line.c\
		utils/get_next_line_utils.c\
		utils/utils_libft.c\
		ft_printf/ft_printf.c\
		ft_printf/ft_char.c\
		ft_printf/ft_digit.c\
		ft_printf/ft_hex.c\
		utils/sound.c\

SRC_BONUS = bonus/main_bonus.c\
			bonus/print_map_bonus.c\
			bonus/move_with_keys_bonus.c\
			bonus/read_map_bonus.c\
			bonus/ft_itoa_bonus.c\
			bonus/destroy_game_bonus.c\
			bonus/ft_free_bonus.c\
			bonus/position_p_bonus.c\
			bonus/any_key_bonus.c\
			bonus/move_enemy.c\
			utils/errors.c\
			utils/get_next_line.c\
			utils/get_next_line_utils.c\
			utils/utils_libft.c\
			ft_printf/ft_char.c\
			ft_printf/ft_digit.c\
			ft_printf/ft_hex.c\
			ft_printf/ft_printf.c\
			utils/sound.c\
			utils/sound_bonus.c\
			bonus/animation_enemy.c\

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:%.c=%.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

bonus: $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) -o $(NAME_BONUS)

clean :
		@rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
		rm -rf $(NAME) $(NAME_BONUS)

re : fclean all bonus