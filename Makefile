# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 17:18:57 by bkandemi          #+#    #+#              #
#    Updated: 2022/06/26 15:38:33 by bkandemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bkandemi.filler

C_FILES = main.c\
		get_info.c\
		init_maps.c\
		get_pos_map.c\
		get_skip_map.c\
		get_dist_map.c\
		set_dist_list.c\
		place.c\
		clean_up.c
		

O_FILES = $(C_FILES:.c=.o)

CC = gcc

CC_DEBUG = gcc -g -fsanitize=address

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(FLAGS) -c $(C_FILES)
	@$(CC) $(FLAGS) $(O_FILES) libft/libft.a -o $(NAME)

clean:
	@rm -f $(O_FILES)
	@make -C libft/ clean
 
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ clean

debug:
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(FLAGS) -c $(C_FILES)
	@$(CC_DEBUG) $(FLAGS) $(O_FILES) libft/libft.a -o $(NAME)

re:	fclean all