/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/05/27 15:09:10 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;
	char *player_info;
	char *map_size;
	char *piece_info;
	int player_number;
	int row;
	int col;
	char **map;
	char **piece;
	int piece_row = 0;
	int piece_col = 0;
	
	row = 0;
	col = 0;

	fd = open("/Users/bengisu/Desktop/HIVE_III/Filler/output.txt", O_WRONLY | O_APPEND);
	
	if (get_next_line(0, &line) == 1 && (player_info = ft_strchr(line, 'p')))
	{
		//write(fd, player_info, ft_strlen(player_info));
		//write(fd, "\n", 1);
		player_number = ft_atoi(player_info + 1);
		ft_putnbr_fd(player_number, fd);
		write(fd, "\n", 1);
	}
	if (get_next_line(0, &line) == 1 && (map_size = ft_strstr(line, "Plateau")))
	{
		//write(fd, map_size, ft_strlen(map_size));
		//write(fd, "\n", 1);
		row = ft_atoi(ft_strchr(line, ' ') + 1);
		col = ft_atoi(ft_strrchr(line, ' ') + 1);
		ft_putnbr_fd(row, fd);
		write(fd, "\n", 1);
		ft_putnbr_fd(col, fd);
		write(fd, "\n", 1);
	}
	get_next_line(0, &line); //to skip col coordinates line
	int i = 0;
	
	map = (char **)malloc(sizeof (char *) * row);
	while (i < row)
	{
		get_next_line(0, &line);
		map[i] = ft_strsub(line, 4, col + 1);
		write(fd, map[i], ft_strlen(map[i]));
		write(fd, "\n", 1);
		i++;
	}
	if (get_next_line(0, &line) == 1 && (piece_info = ft_strstr(line, "Piece")))
	{
		piece_row = ft_atoi(ft_strchr(line, ' ') + 1);
		piece_col = ft_atoi(ft_strrchr(line, ' ') + 1);
		ft_putnbr_fd(piece_row, fd);
		write(fd, "\n", 1);
		ft_putnbr_fd(piece_col, fd);
		write(fd, "\n", 1);
	}
	piece = (char **)malloc(sizeof(char *) * piece_row);
	i = 0;
	while (i < piece_row)
	{
		get_next_line(0, &line);
		piece[i] = ft_strsub(line, 0, piece_col);
		write(fd, piece[i], piece_col);
		write(fd, "\n", 1);
		i++;
	}
	return (0);
}