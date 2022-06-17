/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:53:33 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/17 13:36:15 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> //DELETE

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
			j++;
		}
		if (!swapped)
			break;
		i++;
	}	
}

/*void	merge_sort_dist_list(t_distance *list, t_info *info, t_maps **maps)
{
	int first;
	int last;
}*/

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

static int	is_placeable(t_info *info, t_coord coord, t_maps **maps)
{
	int row;
	int col;
	int found;

	found = FALSE;
	if (coord.y + info->piece_row > info->map_row || coord.x + info->piece_col > info->map_col)
		return (FALSE);
	row = 0;
	while (row < info->piece_row)
	{
		col = 0;
		
		while (col < info->piece_col)
		{
			
			if (maps[coord.y + row][coord.x + col].pos == -2 && info->piece[row][col] == '*')
				return (FALSE);
			if (maps[coord.y + row][coord.x + col].pos == -1 && info->piece[row][col] == '*')
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

void	put_piece(t_info *info, t_distance *list, t_maps **maps)
{
	unsigned int	i;
	unsigned int	size;

	size = info->dist_size;

	//write(fd, "test\n", 5);
	i = 0;
	while (i < size)
	{
		/*ft_putnbr_fd(list[i].coord.y, fd);
		write(fd, " ", 1);
		ft_putnbr_fd(list[i].coord.x, fd);
		write(fd, "\n", 1);*/
		if (is_placeable(info, list[i].coord, maps))
		{
			//write(fd, "test3\n", 6);
			ft_putnbr(list[i].coord.y);
			//ft_putnbr_fd(list[i].coord.y ,fd);
			write(1, " ", 1);
			//write(fd, " ", 1);
			ft_putnbr(list[i].coord.x);
			//ft_putnbr_fd(list[i].coord.x ,fd);
			//write(fd, "\n", 1);
			write(1, "\n", 1);
			return ;
		}
		i++;
	}
	//write(fd, "0 0\n", 4);
	write(1, "0 0\n", 4);
}

