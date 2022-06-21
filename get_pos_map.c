/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:49:46 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/21 11:05:34 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_maps	**init_maps(int row_size, int col_size)
{
	int		i;
	int		j;
	t_maps	**maps;

	maps = (t_maps **)malloc(sizeof(t_maps *) * row_size);
	if (!maps)
		return (NULL);
	i = 0;
	while (i < row_size)
	{
		maps[i] = (t_maps *)malloc(sizeof(t_maps) * col_size);
		if (!maps[i])
			return (NULL); //free ??
		j = 0;
		while (j < col_size)
		{
			maps[i][j].pos = 0;
			maps[i][j].dist = 0;
			maps[i][j].skip = FALSE;
			maps[i][j].move = 0;
			j++;
		}
		i++;
	}
	return (maps);
}

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
