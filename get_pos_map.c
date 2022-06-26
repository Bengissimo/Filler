/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:49:46 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/26 11:39:08 by bkandemi         ###   ########.fr       */
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
		if (!(maps[i]))
		{
			free_maps(maps, i);
			return (NULL);
		}
		j = 0;
		while (j < col_size)
		{
			maps[i][j].pos = 0;
			maps[i][j].skip = FALSE;
			maps[i][j].move = 0;
			j++;
		}
		i++;
	}
	return (maps);
}

static int	verify_line(char *line, int row, char **start)
{
	get_next_line(0, &line);
	if (ft_atoi(line) != row)
	{
		if (line)
			free(line);
		return (FALSE);
	}
	*start = ft_strchr(line, ' ') + 1;
	if (!(*start))
	{
		if (line)
			free(line);
		return (FALSE);
	}
	if (line)
		free(line);
	return (TRUE);
}

int	get_pos_map(t_filler *fill, char *line)
{
	t_coord	co;
	char	*start;

	co.y = 0;
	fill->is_new = FALSE;
	while (co.y < fill->map_row)
	{
		if (!verify_line(line, co.y, &start))
			return (FALSE);
		co.x = 0;
		while (co.x < fill->map_col)
		{
			if (start[co.x] == fill->foe && fill->maps[co.y][co.x].pos == 0)
			{
				fill->maps[co.y][co.x].pos = -2;
				fill->is_new = TRUE;
				fill->maps[co.y][co.x].move = fill->move_count;
			}
			else if (start[co.x] == fill->me && fill->maps[co.y][co.x].pos == 0)
				fill->maps[co.y][co.x].pos = -1;
			co.x++;
		}
		co.y++;
	}
	return (TRUE);
}
