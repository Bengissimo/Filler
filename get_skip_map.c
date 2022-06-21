/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_skip_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:00:02 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/21 11:10:15 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_nearby_free(t_info *info, t_maps **maps, t_coord coord)
{
	int	i;
	int	j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (coord.x + j > 0 && coord.x + j < info->map_col
				&& coord.y + i > 0 && coord.y + i < info->map_row)
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

void	get_skip_map(t_info *info, t_maps **maps)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < info->map_row)
	{
		coord.x = 0;
		while (coord.x < info->map_col)
		{
			if (maps[coord.y][coord.x].skip == FALSE
			&& (maps[coord.y][coord.x].pos == -2 || !is_nearby_free(info, maps, coord)))
				maps[coord.y][coord.x].skip = TRUE;
			coord.x++;
		}
		coord.y++;
	}	
}
