/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:53:33 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/08 19:06:18 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //DELETE

t_distance *parse_distance_list(t_info *info)
{
	int	row;
	int	col;
	int	i;
	t_distance *list;

	list = (t_distance *)malloc(sizeof(*list) * info->map_row * info->map_col);
	row = 0;
	i = 0;
	while (row < info->map_row)
	{
		col = 0;
		while (col < info->map_col)
		{
			list[i].dist = info->map[row][col];
			list[i].coord.x = col;
			list[i].coord.y = row;
			col++;
			i++;
		}
		row++;
	}
	return (list);
	/*i = 0;
	while (i < 100)
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
	}*/
}

void	sort_distance_list(t_distance *list)
{
	int i;
	int j;
	t_distance temp;
	
	i = 0;
	while (i < 100 - 1)
	{
		j = 0;
		while (j < 100 - i - 1)
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

/*void	free_distance_list()
{
	
}*/

void print_dist_list(t_distance *list, int fd)
{
	int i;

	i = 0;
	while (i < 100)
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
