/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:01:49 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/20 15:03:33 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static unsigned int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static unsigned int ft_max(unsigned int nb1, unsigned int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

static int	min_distance(t_info *info, t_maps **maps, t_coord coord)
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
				dist = ft_max(ft_abs(coord.x - col), ft_abs(coord.y - row));
				if (dist < min_dist)
					min_dist = dist;
			}
			col++;
		}
		row++;
	}
	return (min_dist);
}

void	get_dist_map(t_info *info, t_maps **maps)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < info->map_row)
	{
		coord.x = 0;
		while (coord.x < info->map_col)
		{
			
			if (maps[coord.y][coord.x].skip == TRUE)
				maps[coord.y][coord.x].dist = 0;
			else
				maps[coord.y][coord.x].dist = min_distance(info, maps, coord);
			coord.x++;
		}
		coord.y++;
	}
}
