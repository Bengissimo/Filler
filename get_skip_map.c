/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_skip_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:00:02 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/25 10:23:23 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_nearby_free(t_filler *filler, t_coord coord)
{
	int	i;
	int	j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (coord.x + j > 0 && coord.x + j < filler->map_col
				&& coord.y + i > 0 && coord.y + i < filler->map_row)
			{
				if (filler->maps[coord.y + i][coord.x + j].pos == 0)
					return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

void	get_skip_map(t_filler *filler)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < filler->map_row)
	{
		coord.x = 0;
		while (coord.x < filler->map_col)
		{
			if (filler->maps[coord.y][coord.x].skip == FALSE)
			{
				if (filler->maps[coord.y][coord.x].pos == -2
					|| !is_nearby_free(filler, coord))
					filler->maps[coord.y][coord.x].skip = TRUE;
			}
			coord.x++;
		}
		coord.y++;
	}	
}
