# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 09:45:39 by msaouab           #+#    #+#              #
#    Updated: 2022/02/08 23:16:48 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

HEADER = so_long.h

SRC =	main.c\
		move_with_keys.c\
		utils_libft.c\
		print_map.c\
		read_map.c\
		ft_split.c\
		errors.c\
		get_next_line.c\
		get_next_line_utils.c\

SRC_BONUS = bonus/main_bonus.c\
			bonus/print_map_bonus.c\
			bonus/move_with_keys_bonus.c\
			bonus/utils_libft_bonus.c\
			bonus/ft_split_bonus.c\
			bonus/read_map_bonus.c\
			bonus/errors_bonus.c\
			bonus/ft_itoa_bonus.c\
			get_next_line.c\
			get_next_line_utils.c\

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:%.c=%.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

# bonus : $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#cc -I /usr/local/include main.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	
#cc -I /usr/local/include main.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

# %.o: %.c $(HEADER)
# 	$(CC) $(CFLAGS) -Imlx -c $<

clean :
		rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
		rm -rf $(NAME) $(NAME_BONUS)

re : fclean all bonus