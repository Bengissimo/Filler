/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/04 23:02:37 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

void	init_filler(t_info *info)
{
	info->piece_row = 0;
	info->piece_col = 0;
	info->map_row = 0;
	info->map_col = 0;
	info->player_nb = 0;
	info->foe_prev.x = -2;
	info->foe_prev.y = -2;
	info->my_prev.x = -2;
	info->my_prev.y = -2;
	info->foe_curr.x = -1;
	info->foe_curr.y = -1;
	info->my_curr.x = -1;
	info->my_curr.y = -1;
}

/*void	init_way(t_way *way)
{
	way->x = -2;
	way->y = -2;
	way->down = FALSE;
	way->down_left = FALSE;
	way->down_right = FALSE;
	way->up = FALSE;
	way->up_left = FALSE;
	way->up_right = FALSE;
	way->left = FALSE;
	way->right = FALSE;
}*/

void	get_player_nb(t_info *info, char *line, int fd)
{
	char	*player_info;
	//write(fd, "debug\n", 6);
	if ((player_info = ft_strchr(line, 'p')))
	{
		//write(fd, player_info, ft_strlen(player_info));
		//write(fd, "\n", 1);
		info->player_nb = ft_atoi(player_info + 1);
		ft_putnbr_fd(info->player_nb, fd);
		write(fd, "\n", 1);
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

void	get_map_size(t_info *info, char *line, int fd)
{
	char	*map_size;
	//write(fd, "debug\n", 6);
	if ((map_size = ft_strstr(line, "Plateau")))
	{
		//write(fd, map_size, ft_strlen(map_size));
		//write(fd, "\n", 1);
		info->map_row = ft_atoi(ft_strchr(line, ' ') + 1);
		info->map_col = ft_atoi(ft_strrchr(line, ' ') + 1);
		ft_putnbr_fd(info->map_row, fd);
		write(fd, "\n", 1);
		ft_putnbr_fd(info->map_col, fd);
		write(fd, "\n", 1);
	}
}

void	parse_map(t_info *info)
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
			{
				info->map[row][col] = -2;
			}
			else if (start[col] == info->me)
			{
				info->map[row][col] = -1;
			}
			else
				info->map[row][col] = 0;
			col++;
		}
		row++;
	}
}

void get_piece_size(t_info *info, char *line, int fd)
{
	info->piece_row = ft_atoi(ft_strchr(line, ' ') + 1);
	info->piece_col = ft_atoi(ft_strrchr(line, ' ') + 1);
	ft_putnbr_fd(info->piece_row, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(info->piece_col, fd);
	write(fd, "\n", 1);
}

void parse_piece(t_info *info, int fd)
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
		write(fd, info->piece[i], info->piece_col);
		write(fd, "\n", 1);
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
			if (info->map[i][j] == 0)
				write(fd, "  ", 2);
			else
				write(fd, " ", 1);
		}
		write(fd, "\n", 1);
	}
}

int main(void)
{
	t_info info;
	char	*line;
	int fd;
	
	init_filler(&info);
	fd = open("/Users/bengisu/Desktop/HIVE_III/Filler/output.txt", O_WRONLY | O_APPEND);
	while(TRUE)
	{
		if (get_next_line(0, &line) != 1)
			return (1);
		if (info.player_nb == 0)
			get_player_nb(&info, line, fd);
		if (info.map_row == 0 && info.map_col == 0)
			get_map_size(&info, line, fd);
		if (ft_strstr(line, "0123456789"))
		{
			parse_map(&info);
			print_map(&info, fd);
		}
		if (ft_strstr(line, "Piece"))
		{
			get_piece_size(&info, line, fd);
			parse_piece(&info, fd);
		}
		write(1, "5 6\n", 6);
	}
	return (0);
}
