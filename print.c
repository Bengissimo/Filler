/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:18:30 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/25 09:51:48 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_dist_list(t_dist *list, int fd, t_filler *filler)
{
	unsigned int i;

	i = 0;
	while (i < filler->dist_size)
	{
		write(fd, "x: ", 3);
		ft_putnbr_fd(list[i].coord.x, fd);
		write(fd, " ", 1);
		write(fd, "y: ", 3);
		ft_putnbr_fd(list[i].coord.y, fd);
		write(fd, " ", 1);
		write(fd, "dist: ", 6);
		ft_putnbr_fd(list[i].dist, fd);
		write(fd, "\n", 1);
		i++;
	}
}

void print_map(t_filler *filler, t_maps **maps, int fd)
{
	for (int i = 0; i < filler->map_row; i++)
	{
		for (int j = 0; j < filler->map_col; j++)
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

void print_dist_map(t_filler *filler, t_maps **maps, int fd)
{
	for (int i = 0; i < filler->map_row; i++)
	{
		for (int j = 0; j < filler->map_col; j++)
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

void print_skip_map(t_filler *filler, t_maps **maps, int fd)
{
	for (int i = 0; i < filler->map_row; i++)
	{
		for (int j = 0; j < filler->map_col; j++)
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
