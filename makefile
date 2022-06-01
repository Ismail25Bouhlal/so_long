# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 12:09:10 by ibouhlal          #+#    #+#              #
#    Updated: 2022/05/28 15:31:28 by ibouhlal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
 
NAME = so_long

NAME_B = so_long_bonus

CFLAGS = -Wall -Wextra -Werror -Imlx -g

PRINTF = ft_printf/libftprintf.a

SRC =  mandatore/mlx_game/position_of_player.c \
		mandatore/mlx_game/mlx.c \
		mandatore/mlx_game/finish.c \
		mandatore/mlx_game/player_mouvement.c \
		mandatore/parssing/check_all.c \
		mandatore/parssing/check_map.c \
		mandatore/parssing/check_name.c \
		mandatore/parssing/wals_check.c\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		mandatore/so_long.c 
		
SRC_B =  bonnus/mlx_game_bonnus/player_mouvement.c \
		 bonnus/mlx_game_bonnus/mlx_bonus.c \
		 bonnus/mlx_game_bonnus/position_of_player.c \
		 bonnus/mlx_game_bonnus/finish.c \
		 bonnus/mlx_game_bonnus/enemie_mouvement.c \
		 bonnus/mlx_game_bonnus/enemi_position.c \
		 bonnus/mlx_game_bonnus/tools.c \
		 bonnus/parssing_bonnus/check_all.c \
		 bonnus/parssing_bonnus/check_map.c \
		 bonnus/parssing_bonnus/check_name.c \
		 bonnus/parssing_bonnus/wals_check.c \
		 get_next_line/get_next_line.c \
		 get_next_line/get_next_line_utils.c \
		 bonnus/so_long_bonnus.c

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

$(NAME) :  $(PRINTF) $(OBJ)	mandatore/so_long.h
	@echo "Making so_long"
	@$(CC) $(OBJ) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_B) : $(PRINTF) $(OBJ_B) bonnus/so_long_bonnus.h
	@echo "Making so_long_bonus"
	@$(CC) $(OBJ_B) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

$(PRINTF) :
	@echo "Making ft_printf"
	@make -C ft_printf

all : $(NAME)

bonus : $(NAME_B)

clean :
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_B)
	@make -C ft_printf clean

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_B)
	@make -C ft_printf fclean

re : fclean all

rb : fclean bonus
