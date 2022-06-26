/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:49:46 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/26 15:29:33 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	verify_line(char *line, int row, char **start)
{
	get_next_line(0, &line);
	if (ft_atoi(line) != row)
	{
		ft_strdel(&line);
		return (FALSE);
	}
	*start = ft_strchr(line, ' ') + 1;
	if (!(*start))
	{
		ft_strdel(&line);
		return (FALSE);
	}
	ft_strdel(&line);
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
