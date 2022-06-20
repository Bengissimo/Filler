/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:49:46 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/20 14:50:16 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_pos_map(t_info *info, t_maps **maps)
{
	int		row;
	int		col;
	char	*line;
	char	*start;

	row = 0;
	info->is_new = FALSE;
	while (row < info->map_row)
	{
		get_next_line(0, &line);
		if (ft_atoi(line) != row)
			return (FALSE);
		start = ft_strchr(line, ' ') + 1;
		if (!start)
			return (FALSE);
		col = 0;
		while (col < info->map_col)
		{
			if (start[col] == info->foe && maps[row][col].pos == 0)
			{
				maps[row][col].pos = -2;
				info->is_new = TRUE;
				maps[row][col].move = info->move_count;
			}
			else if (start[col] == info->me && maps[row][col].pos == 0)
				maps[row][col].pos = -1;
			col++;
		}
		row++;
	}
	return (TRUE);
}

void	get_skip_map(t_info *info, t_maps **maps)
{
	t_coord coord;

	coord.y = 0;
	while(coord.y < info->map_row)
	{
		coord.x = 0;
		while (coord.x < info->map_col)
		{
			if (maps[coord.y][coord.x].skip == FALSE && (maps[coord.y][coord.x].pos == -2 || !check_if_nearby_free(info, maps, coord)))
				maps[coord.y][coord.x].skip = TRUE;
			coord.x++;
		}
		coord.y++;
	}	
}