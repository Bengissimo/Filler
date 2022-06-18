/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:13:47 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/18 14:14:55 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_distance	*init_list(t_info *info)
{
	unsigned int	size;
	unsigned int	i;
	t_distance *list;

	size = info->map_col * info->map_row;
	//write(fd, "initlist\n", 9);
	//ft_putnbr_fd(size, fd);
	//write(fd, "\n", 1);
	list = (t_distance *)malloc(sizeof(t_distance) * size);
	if (!list)
		return (NULL);
	i = 0;
	while (i < size)
	{
		list[i].dist = info->map_col + info->map_row; //this should be the max value, to make sorting easier
		list[i].move = 0;
		i++;
	}
	return (list);
}

void	parse_distance_list(t_distance *list, t_info *info, t_maps **maps)
{
	int				row;
	int				col;
	unsigned int	i;
	//buraya list  size eklemeyi dusun

	row = 0;
	i = 0;
	while (row < info->map_row)
	{
		col = 0;
		while (col < info->map_col)
		{
			if (maps[row][col].dist > 0)
			{
				list[i].dist = maps[row][col].dist;
				list[i].move = maps[row][col].move;
				list[i].coord.x = col;
				list[i].coord.y = row;
				i++;
			}
			col++;
		}
		row++;
	}
	info->dist_size = i;
}

void	sort_distance_list(t_distance *list, t_info *info)
{
	unsigned int	i;
	unsigned int	j;
	t_distance		temp;
	unsigned int	size;
	int swapped;
	
	swapped = FALSE;
	i = 0;
	size = info->dist_size;
	if (size == 0)
		return ;
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
				swapped = TRUE;
			}
			else if (list[j].dist == list[j + 1].dist && list[j].move < list[j + 1].move)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
				swapped = TRUE;
			}
			j++;
		}
		if (!swapped)
			break;
		i++;
	}	
}

void	free_distance_list(t_distance *list)
{
	free(list);
	list = NULL;
}

void print_dist_list(t_distance *list, int fd, t_info *info)
{
	unsigned int i;

	i = 0;
	while (i < info->dist_size)
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