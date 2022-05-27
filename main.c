/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/05/27 20:33:43 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

void	init_filler(t_filler *filler)
{
	filler->piece_row = 0;
	filler->piece_col = 0;
	filler->map_row = 0;
	filler->map_col = 0;
	filler->player_nb = 0;
}

void	get_player_nb(t_filler *filler, char *line, int fd)
{
	char	*player_info;
	//write(fd, "debug\n", 6);
	if ((player_info = ft_strchr(line, 'p')))
	{
		//write(fd, player_info, ft_strlen(player_info));
		//write(fd, "\n", 1);
		filler->player_nb = ft_atoi(player_info + 1);
		ft_putnbr_fd(filler->player_nb, fd);
		write(fd, "\n", 1);
	}
}

void	get_map_size(t_filler *filler, char *line, int fd)
{
	char	*map_size;
	//write(fd, "debug\n", 6);
	if ((map_size = ft_strstr(line, "Plateau")))
	{
		//write(fd, map_size, ft_strlen(map_size));
		//write(fd, "\n", 1);
		filler->map_row = ft_atoi(ft_strchr(line, ' ') + 1);
		filler->map_col = ft_atoi(ft_strrchr(line, ' ') + 1);
		ft_putnbr_fd(filler->map_row, fd);
		write(fd, "\n", 1);
		ft_putnbr_fd(filler->map_col, fd);
		write(fd, "\n", 1);
	}
}

void	parse_map(t_filler *filler, int fd)
{
	int		i;
	char	*line;

	filler->map = (char **)malloc(sizeof(char *) * filler->map_row);
	if (!filler->map)
		return ;
	i = 0;
	while (i < filler->map_row)
	{
		get_next_line(0, &line);
		filler->map[i] = (char *)malloc(sizeof(char) * (filler->map_col + 1));
		ft_strcpy(filler->map[i], (ft_strchr(line, ' ') + 1));
		write(fd, filler->map[i], ft_strlen(filler->map[i]));
		write(fd, "\n", 1);
		i++;
	}
}

void get_piece_size(t_filler *filler, char *line, int fd)
{
	filler->piece_row = ft_atoi(ft_strchr(line, ' ') + 1);
	filler->piece_col = ft_atoi(ft_strrchr(line, ' ') + 1);
	ft_putnbr_fd(filler->piece_row, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(filler->piece_col, fd);
	write(fd, "\n", 1);
}

void parse_piece(t_filler *filler, int fd)
{
	int		i;
	char	*line;

	filler->piece = (char **)malloc(sizeof(char *) * filler->piece_row);
	if (!filler->piece)
		return ;
	i = 0;
	while (i < filler->piece_row)
	{
		get_next_line(0, &line);
		filler->piece[i] = (char *)malloc(sizeof(char) * (filler->piece_col + 1));
		ft_strcpy(filler->piece[i], line);
		write(fd, filler->piece[i], filler->piece_col);
		write(fd, "\n", 1);
		i++;
	}
}

int main(void)
{
	t_filler filler;
	char	*line;
	int fd;
	
	init_filler(&filler);
	fd = open("/Users/bengisu/Desktop/HIVE_III/Filler/output.txt", O_WRONLY | O_APPEND);
	while(TRUE)
	{
		if (get_next_line(0, &line) != 1)
			return (1);
		if (filler.player_nb == 0)
			get_player_nb(&filler, line, fd);
		if (filler.map_row == 0 && filler.map_col == 0)
			get_map_size(&filler, line, fd);
		if (ft_strstr(line, "0123456789"))
			parse_map(&filler, fd);
		if (ft_strstr(line, "Piece"))
		{
			get_piece_size(&filler, line, fd);
			parse_piece(&filler, fd);
		}
		write(1, "12 14\n", 6);
	}
	return (0);
}
