/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/18 11:30:15 by bkandemi         ###   ########.fr       */
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
	info->dist_size = 0;
	info->is_new = FALSE;
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
			if (maps[i][j].pos <= 9)
				write(fd, "   ", 3);
			else
				write(fd, "  ", 2);
		}
		write(fd, "\n", 1);
	}
	write(fd, "---\n", 4);
}

void print_dist_map(t_info *info, t_maps **maps, int fd)
{
	for (int i = 0; i < info->map_row; i++)
	{
		for (int j = 0; j < info->map_col; j++)
		{
			ft_putnbr_fd(maps[i][j].dist, fd);
			if (maps[i][j].dist <= 9)
				write(fd, "   ", 3);
			else
				write(fd, "  ", 2);
		}
		write(fd, "\n", 1);
	}
	write(fd, "---\n", 4);
}

void print_skip_map(t_info *info, t_maps **maps, int fd)
{
	for (int i = 0; i < info->map_row; i++)
	{
		for (int j = 0; j < info->map_col; j++)
		{
			ft_putnbr_fd(maps[i][j].skip, fd);
			if (maps[i][j].dist <= 9)
				write(fd, "   ", 3);
			else
				write(fd, "  ", 2);
		}
		write(fd, "\n", 1);
	}
	write(fd, "---\n", 4);
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
			if (maps == NULL && info.map_row > 0 && info.map_col > 0)
				maps = init_maps(maps, info.map_row, info.map_col);
			
			parse_map(&info, maps);
			if (info.is_new == FALSE)
				continue ;
			
			//print_map(&info, maps, fd);

			
			//write(fd, "dist before: ", 13);
			//ft_putnbr_fd(maps[8][2].dist, fd);
			//write(fd, "\n", 1);
			//write(fd, "pos: ", 5);
			//ft_putnbr_fd(maps[8][2].pos, fd);
			//write(fd, "\n", 1);
			set_skip(maps, &info);
			//print_skip_map(&info, maps, fd);
			set_dist(&info, maps);
			//print_dist_map(&info, maps, fd);

			//write(fd, "-----\n", 6);
			if (!list)
				list = init_list(&info);
			parse_distance_list(list, &info, maps);
			//print_dist_list(list, fd, &info, maps);
			//write(fd, "-----\n", 6);
			//write(fd, "dist before: ", 13);
			//print_dist_list(list, fd);
			sort_distance_list(list, &info);
			//write(fd, "dist before: ", 13);
			//write(fd, "sorted: \n", 9);
			//print_dist_list(list, fd, &info, maps);
			//write(fd, "-----\n", 6);
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