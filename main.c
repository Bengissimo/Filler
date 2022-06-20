/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/20 10:42:07 by bkandemi         ###   ########.fr       */
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
	info->move_count = 0;
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
			ft_putnbr_fd(maps[i][j].move, fd); //!!! prints MOVE
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
	char		*line;
	t_info		info;
	t_distance	*list;
	t_maps		**maps;
	
	//int fd;
	
	list = NULL;
	maps = NULL;
	init_filler(&info);
	//fd = open("/Users/bkandemi/bkandemi_workspace/filler/output.txt", O_WRONLY | O_APPEND);
	while(TRUE)
	{
		if (get_next_line(0, &line) != 1)
			return (EXIT_ERROR);
		if (info.player_nb == 0)
		{
			if (!get_player_nb(&info, line))
				return (EXIT_ERROR);
		}
		if (info.map_row == 0 && info.map_col == 0)
			get_map_size(&info, line);
		if (ft_strstr(line, "0123456789"))
		{
			if (maps == NULL && info.map_row > 0 && info.map_col > 0)
				maps = init_maps(maps, info.map_row, info.map_col);
			
			parse_map(&info, maps);
			if (info.is_new == FALSE)
				continue ;
			set_skip(maps, &info);
			set_dist(&info, maps);
			if (!list)
				list = init_list(&info);
			parse_distance_list(list, &info, maps);
			sort_distance_list(list, &info);
		}
		if (ft_strstr(line, "Piece"))
		{
			get_piece_size(&info, line);
			parse_piece(&info);
			put_piece(&info, list ,maps);
		}
		info.move_count++;
	}
	free_distance_list(list);
	//free_maps
	return (EXIT_SUCCESS);
}