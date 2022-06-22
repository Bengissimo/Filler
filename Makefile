# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 17:18:57 by bkandemi          #+#    #+#              #
#    Updated: 2022/06/22 22:49:22 by bkandemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bkandemi.filler

C_FILES = main.c\
		put_piece.c\
		list.c\
		get_info.c\
		get_pos_map.c\
		get_skip_map.c\
		get_dist_map.c\
		clean_up.c
		

O_FILES = $(C_FILES:.c=.o)

CC = gcc

CC_DEBUG = /usr/local/opt/llvm/bin/clang -fsanitize=leak

FLAGS = -g -Wall -Wextra -Werror

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