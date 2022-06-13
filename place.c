/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:53:33 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/13 11:47:58 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //DELETE

void	find_playable_pos(t_info *info)
{
	int	row;
	int	col;

	row = 0;
	while (row < info->map_row)
	{
		col = 0;
		while (col < info->map_col)
		{
			if (info->map[row][col] != -2)
				info->playable_pos++;
			col++;
		}
		row++;
	}
}

t_distance	*init_dist_list(t_info *info)
{
	int	i;
	t_distance	*list;

	
	list = (t_distance *)malloc(sizeof(*list) * info->map_col * info->map_row);
	i = 0;
	while (i < info->map_col * info->map_row)
	{
		list[i].coord.x = 0;
		list[i].coord.y = 0;
		list[i].dist = info->map_col + info->map_row; //max dist olaack sekilde ayarliyorum ki sort ederken fazladan islem olmasin
		i++;
	}
	return (list);
}

void parse_distance_list(t_info *info, t_distance *list)
{
	int				row;
	int				col;
	unsigned int	i;
	//write(fd, "parse debug\n", 12);
	row = 0;
	i = 0;
	while (row < info->map_row)
	{
		col = 0;
		while (col < info->map_col)
		{
			if (info->distance_map[row][col] > 0)
			{
				list[i].dist = info->distance_map[row][col];
				list[i].coord.x = col;
				list[i].coord.y = row;
				i++;
			}
			col++;
		}
		row++;
	}
}

void	sort_distance_list(t_distance *list, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	t_distance		temp;
	
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (list[j].dist > list[j + 1].dist)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			j++;
		}
		i++;
	}	
}

void	free_dist_list(t_distance **list)
{
	if (*list && list)
	{
		free(*list);
		list = NULL;
	}
}

void print_dist_list(t_distance *list, unsigned int size, int fd)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		write(fd, "x: ", 3);
		ft_putnbr_fd(list[i].coord.x, fd);
		write(fd, "\n", 1);
		write(fd, "y: ", 3);
		ft_putnbr_fd(list[i].coord.y, fd);
		write(fd, "\n", 1);
		write(fd, "dist: ", 6);
		ft_putnbr_fd(list[i].dist, fd);
		write(fd, "\n", 1);
		write(fd, "\n", 1);
		i++;
	}
}

static int	is_placeable(t_info *info, t_coord coord)
{
	int row;
	int col;
	int found;

	found = FALSE;
	//write(fd, "debug1\n", 7);
	if (coord.y + info->piece_row > info->map_row || coord.x + info->piece_col > info->map_col)
		return (FALSE);
	/*ft_putnbr_fd(info->piece_row, fd);
	write(fd, " ", 1);
	ft_putnbr_fd(info->piece_col, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(info->map_row, fd);
	write(fd, " ", 1);
	ft_putnbr_fd(info->map_col, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(coord.y, fd);
	write(fd, " ", 1);
	ft_putnbr_fd(coord.x, fd);
	write(fd, "\n", 1);*/
	row = 0;
	while (row < info->piece_row)
	{
		col = 0;
		
		while (col < info->piece_col)
		{
			//write(fd, "debug2\n", 7);
			if (info->map[coord.y + row][coord.x + col] == -2 && info->piece[row][col] == '*')
				return (FALSE);
			else if (info->map[coord.y + row][coord.x + col] == -1 && info->piece[row][col] == '*')
			{
				if (found)
					return (FALSE);
				found = TRUE;
			}
			col++;
		}
		row++;
	}	
	return (found);
}

void	put_piece(t_info *info, t_distance *list)
{
	unsigned int	i;

	//write(fd, "test\n", 5);
	if (!list)
		return ;
	i = 0;
	while (i < info->playable_pos)
	{
		/*ft_putnbr_fd(list[i].coord.y, fd);
		write(fd, " ", 1);
		ft_putnbr_fd(list[i].coord.x, fd);
		write(fd, "\n", 1);*/
		if (is_placeable(info, list[i].coord))
		{
			//write(fd, "test3\n", 6);
			ft_putnbr(list[i].coord.y);
			write(1, " ", 1);
			ft_putnbr(list[i].coord.x);
			write(1, "\n", 1);
			return ;
		}
		i++;
	}
	write(1, "0 0\n", 4);
}
