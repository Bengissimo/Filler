/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/13 12:03:27 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h> //DELETE LATER

unsigned int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void	init_filler(t_info *info)
{
	info->piece_row = 0;
	info->piece_col = 0;
	info->map_row = 0;
	info->map_col = 0;
	info->player_nb = 0;
	info->playable_pos = 0;
	info->distance_map = NULL;
	info->map = NULL;
	info->piece = NULL;
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

int	**malloc_map(t_info *info)
{
	int	i;
	int	j;
	int **map;

	map = (int **)malloc(sizeof(int *) * info->map_row);
	i = 0;
	while (i < info->map_row)
	{
		map[i] = (int *)malloc(sizeof(int) * info->map_col);
		j = 0;
		while (j < info->map_col)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

void	parse_map(t_info *info)
{
	int		row;
	int		col;
	char	*line;
	char	*start;

	if (!info->map)
		info->map = malloc_map(info);
	row = 0;
	while (row < info->map_row)
	{
		get_next_line(0, &line);
		start = ft_strchr(line, ' ') + 1;
		col = 0;
		while (col < info->map_col)
		{
			if (start[col] == info->foe && info->map[row][col] != -2)
				info->map[row][col] = -2;
			else if (start[col] == info->me && info->map[row][col] != -1)
				info->map[row][col] = -1;
			col++;
		}
		row++;
	}
}

int	calc_rel_distance(t_info *info, t_coord coord)
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

void get_distance_map(t_info *info)
{
	t_coord	coord;

	if (!info->distance_map)
		info->distance_map = malloc_map(info);
	coord.y = 0;
	while (coord.y < info->map_row)
	{
		coord.x = 0;
		while (coord.x < info->map_col)
		{
			if (info->map[coord.y][coord.x] == 0 || info->map[coord.y][coord.x] == -1)
				info->distance_map[coord.y][coord.x] = calc_rel_distance(info, coord);
			coord.x++;
		}
		coord.y++;
	}
}

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


void print_map(t_info *info, int fd)
{
	for (int i = 0; i < info->map_row; i++)
	{
		for (int j = 0; j < info->map_col; j++)
		{
			ft_putnbr_fd(info->map[i][j], fd);
			if (info->map[i][j] >= 0 && info->map[i][j] <= 9)
				write(fd, "   ", 3);
			else
				write(fd, "  ", 2);
		}
		write(fd, "\n", 1);
	}
}

void print_dist_map(t_info *info, int fd)
{
	for (int i = 0; i < info->map_row; i++)
	{
		for (int j = 0; j < info->map_col; j++)
		{
			ft_putnbr_fd(info->distance_map[i][j], fd);
			if (info->distance_map[i][j] >= 0 && info->distance_map[i][j] <= 9)
				write(fd, "   ", 3);
			else
				write(fd, "  ", 2);
		}
		write(fd, "\n", 1);
	}
}

void	free_distance_map(int **map, int index)
{
	int i;
	
	i = 0;
	while (i < index)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int main(void)
{
	t_info info;
	t_distance *list;
	char	*line;
	//int fd;
	
	list = NULL;
	init_filler(&info);
	//fd = open("/Users/bkandemi/bkandemi_workspace/filler/output.txt", O_WRONLY | O_APPEND);
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
			parse_map(&info);
			//print_map(&info, fd);
			get_distance_map(&info);
			//write(fd, "\n\n", 2);
			//print_dist_map(&info, fd);
			if (!list)
				list = init_dist_list(&info);
			parse_distance_list(&info, list);
			//write(fd, "debug\n", 6);
			find_playable_pos(&info);
			//print_dist_list(list, info.playable_pos, fd);
			sort_distance_list(list, info.playable_pos);
			//write(fd, "sorted: \n", 9);
			//print_dist_list(list, fd);
		}
		if (ft_strstr(line, "Piece"))
		{
			get_piece_size(&info, line);
			parse_piece(&info);
			//write(fd, "debug\n", 6);
			put_piece(&info, list);
		}
	}
	free_dist_list(&list);
	return (0);
}
