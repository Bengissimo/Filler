/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:08:28 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/15 16:32:09 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static unsigned int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

t_maps	**init_maps(t_maps **maps, int row_size, int col_size, int fd)
{
	int		i;
	int		j;
	//write(fd, "test\n", 5);
	fd =0;
	maps = (t_maps **)malloc(sizeof(t_maps *) * row_size);
	if (!maps)
		return NULL;
	i = 0;
	while (i < row_size)
	{
		maps[i] = (t_maps *)malloc(sizeof(t_maps) * col_size);
		if (!maps[i])
			return NULL;
		j = 0;
		while (j < col_size)
		{
			maps[i][j].coord.x = j;
			maps[i][j].coord.y = i;
			maps[i][j].pos = 0;
			maps[i][j].dist = 0;
			j++;
		}
		i++;
	}
	return (maps);
}

void	parse_map(t_info *info, t_maps **maps, int fd)
{
	int		row;
	int		col;
	char	*line;
	char	*start;

	fd = 0;
	row = 0;
	while (row < info->map_row)
	{
		
		get_next_line(0, &line);
		start = ft_strchr(line, ' ') + 1;
		col = 0;
		while (col < info->map_col)
		{
			//write(fd, "tes3\n", 5);
			/*if (start[col] != info->foe || start[col] != info->me || start[col] != '.')
				return ;*/
			if (start[col] == info->foe && maps[row][col].pos == 0)
				maps[row][col].pos = -2;
			else if (start[col] == info->me && maps[row][col].pos == 0)
				maps[row][col].pos = -1;
			col++;
		}
		row++;
	}
	//return (TRUE);
}

int	min_distance(t_info *info, t_maps **maps, t_coord coord)
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
			if (maps[row][col].pos == -2)
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

int	check_if_nearby_free(t_info *info, t_maps **maps, t_coord coord)
{
	int i;
	int j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (coord.x + j > 0 && coord.x + j < info->map_col &&
			coord.y + i > 0 && coord.y + i < info->map_row)
			{
				if (maps[coord.y + i][coord.x + j].pos == 0)
					return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

void set_dist(t_info *info, t_maps **maps)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < info->map_row)
	{
		coord.x = 0;
		while (coord.x < info->map_col)
		{
			if (maps[coord.y][coord.x].pos == 0)
				maps[coord.y][coord.x].dist = min_distance(info, maps, coord);
			else if (maps[coord.y][coord.x].pos == -1)
			{
				if (check_if_nearby_free(info, maps, coord))
					maps[coord.y][coord.x].dist = min_distance(info, maps, coord);
			}
			else
				maps[coord.y][coord.x].dist = 0;
			coord.x++;
		}
		coord.y++;
	}
}
