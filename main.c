/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/15 22:53:36 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h> //DELETE LATER



void	init_filler(t_info *info)
{
	info->piece_row = 0;
	info->piece_col = 0;
	info->map_row = 0;
	info->map_col = 0;
	info->player_nb = 0;
}

void	get_player_nb(t_info *info, char *line)
{
	char	*player_info;
	//write(fd, "debug\n", 6);
	if ((player_info = ft_strchr(line, 'p')))
	{
		//write(fd, player_info, ft_strlen(player_info));
		//write(fd, "\n", 1);
		info->player_nb = ft_atoi(player_info + 1);
		//ft_putnbr_fd(info->player_nb, fd);
		//write(fd, "\n", 1);
	}
	if (info->player_nb == 1)
	{
		info->me = 'O';
		info->foe = 'X';
	}
	else
	{
		info->me = 'X';
		info->foe = 'O';
	}
}

void	get_map_size(t_info *info, char *line)
{
	char	*map_size;
	//write(fd, "debug\n", 6);
	if ((map_size = ft_strstr(line, "Plateau")))
	{
		//write(fd, map_size, ft_strlen(map_size));
		//write(fd, "\n", 1);
		info->map_row = ft_atoi(ft_strchr(line, ' ') + 1);
		info->map_col = ft_atoi(ft_strrchr(line, ' ') + 1);
		//ft_putnbr_fd(info->map_row, fd);
		//write(fd, "\n", 1);
		//ft_putnbr_fd(info->map_col, fd);
		//write(fd, "\n", 1);
	}
}

/*void	parse_map(t_info *info)
{
	int		row;
	int		col;
	char	*line;
	char	*start;

	info->map = (int **)malloc(sizeof(int *) * info->map_row);
	row = 0;
	while (row < info->map_row)
	{
		get_next_line(0, &line);
		start = ft_strchr(line, ' ') + 1;
		info->map[row] = (int *)malloc(sizeof(int) * info->map_col);
		col = 0;
		while (col < info->map_col)
		{
			if (start[col] == info->foe)
				info->map[row][col] = -2;
			else if (start[col] == info->me)
				info->map[row][col] = -1;
			else
				info->map[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	min_distance(t_info *info, t_coord coord)
{
	int				row;
	int				col;
	unsigned int	dist;
	unsigned int	min_dist;

	min_dist = info->map_col + info->map_row;
	row = 0;
	while (row < info->map_row)
	{
		col = 0;
		while (col < info->map_col)
		{
			if (info->map[row][col] == -2)
			{
				dist = ft_abs(coord.x - col) + ft_abs(coord.y - row);
				if (dist < min_dist)
					min_dist = dist;
			}
			col++;
		}
		row++;
	}
	return (min_dist);
}

int	check_if_nearby_free(t_info *info, t_coord coord)
{
	int i;
	int j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (coord.x + j > 0 && coord.x + j < info->map_col &&
			coord.y + i > 0 && coord.y + i < info->map_row)
			{
				if (info->map[coord.y + i][coord.x + j] == 0)
					return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

void calculate_relative_dist(t_info *info)
{
	t_coord	coord;

	info->distance_map = (int **)malloc(sizeof(int *) * info->map_row);
	coord.y = 0;
	while (coord.y < info->map_row)
	{
		coord.x = 0;
		info->distance_map[coord.y] = (int *)malloc(sizeof(int) * info->map_col);
		while (coord.x < info->map_col)
		{
			if (info->map[coord.y][coord.x] == 0)
				info->distance_map[coord.y][coord.x] = min_distance(info, coord);
			else if (info->map[coord.y][coord.x] == -1)
			{
				if (check_if_nearby_free(info, coord))
					info->distance_map[coord.y][coord.x] = min_distance(info, coord);
			}
			coord.x++;
		}
		coord.y++;
	}
}*/

void get_piece_size(t_info *info, char *line)
{
	info->piece_row = ft_atoi(ft_strchr(line, ' ') + 1);
	info->piece_col = ft_atoi(ft_strrchr(line, ' ') + 1);
	/*ft_putnbr_fd(info->piece_row, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(info->piece_col, fd);
	write(fd, "\n", 1);*/
}

void parse_piece(t_info *info)
{
	int		i;
	char	*line;

	info->piece = (char **)malloc(sizeof(char *) * info->piece_row);
	if (!info->piece)
		return ;
	i = 0;
	while (i < info->piece_row)
	{
		get_next_line(0, &line);
		info->piece[i] = (char *)malloc(sizeof(char) * (info->piece_col + 1));
		ft_strcpy(info->piece[i], line);
		//write(fd, info->piece[i], info->piece_col);
		//write(fd, "\n", 1);
		i++;
	}
}


void print_map(t_info *info, t_maps **maps, int fd)
{
	for (int i = 0; i < info->map_row; i++)
	{
		for (int j = 0; j < info->map_col; j++)
		{
			ft_putnbr_fd(maps[i][j].pos, fd);
			if (maps[i][j].pos >= 0 && maps[i][j].pos <= 9)
				write(fd, "   ", 3);
			else
				write(fd, "  ", 2);
		}
		write(fd, "\n", 1);
	}
}

void print_dist_map(t_info *info, t_maps **maps, int fd)
{
	for (int i = 0; i < info->map_row; i++)
	{
		for (int j = 0; j < info->map_col; j++)
		{
			ft_putnbr_fd(maps[i][j].dist, fd);
			if (maps[i][j].dist >= 0 && maps[i][j].dist <= 9)
				write(fd, "   ", 3);
			else
				write(fd, "  ", 2);
		}
		write(fd, "\n", 1);
	}
}

int main(void)
{
	t_info info;
	t_distance *list;
	t_maps **maps;
	char	*line;
	int fd;
	
	list = NULL;
	maps = NULL;
	init_filler(&info);
	fd = open("/Users/bengisu/Desktop/HIVE_III/Filler/output.txt", O_WRONLY | O_APPEND);
	while(TRUE)
	{
		if (get_next_line(0, &line) != 1)
			return (1);
		if (info.player_nb == 0)
			get_player_nb(&info, line);
		if (info.map_row == 0 && info.map_col == 0)
			get_map_size(&info, line);
		if (ft_strstr(line, "0123456789"))
		{
			if (maps == NULL && info.map_row > 0 && info.map_col > 0){
				maps = init_maps(maps, info.map_row, info.map_col, fd);
				//print_map(&info, maps, fd);
				//write(fd, "-----\n", 6);
				}
			
			parse_map(&info, maps, fd);
			print_map(&info, maps, fd);
			write(fd, "\n", 1);
			//write(fd, "dist before: ", 13);
			//ft_putnbr_fd(maps[8][2].dist, fd);
			//write(fd, "\n", 1);
			//write(fd, "pos: ", 5);
			//ft_putnbr_fd(maps[8][2].pos, fd);
			//write(fd, "\n", 1);
			set_skip(maps, &info);
			set_dist(&info, maps);
			//write(fd, "dist before: ", 13);
			//parse_map(&info);
			
			//calculate_relative_dist(&info);
			//write(fd, "\n\n", 2);
			print_dist_map(&info, maps, fd);
			write(fd, "-----\n", 6);
			list = parse_distance_list(&info, maps);
			//write(fd, "dist before: ", 13);
			//print_dist_list(list, fd);
			sort_distance_list(list);
			//write(fd, "dist before: ", 13);
			//write(fd, "sorted: \n", 9);
			//print_dist_list(list, fd);
		}
		if (ft_strstr(line, "Piece"))
		{
			get_piece_size(&info, line);
			parse_piece(&info);
			put_piece(&info, list ,maps);
		}
	}
	free_distance_list(list);
	return (0);
}