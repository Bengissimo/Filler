/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:41:20 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/20 14:32:31 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player_nb(t_info *info, char *line, char *name)
{
	char	*player_info;

	if (info->player_nb != 0)
		return ;
	if (!ft_strstr(line, name))
		return ;
	player_info = ft_strchr(line, 'p');
	if (!player_info)
		return ;
	info->player_nb = ft_atoi(player_info + 1);
	if (!info->player_nb)
		return ;
	if (info->player_nb == 1)
	{
		info->me = 'O';
		info->foe = 'X';
	}
	else if (info->player_nb == 2)
	{
		info->me = 'X';
		info->foe = 'O';
	}
}

int	get_map_size(t_info *info, char *line)
{
	char	*row;
	char	*col;
	
	row = ft_strchr(line, ' ') + 1;
	col = ft_strrchr(line, ' ') + 1;
	if (!row || !col)
		return (FALSE);
	info->map_row = ft_atoi(row);
	info->map_col = ft_atoi(col);
	if (info->map_row <= 0 || info->map_col <= 0)
		return (FALSE);
	return (TRUE);
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

