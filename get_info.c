/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:41:20 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/20 15:20:38 by bkandemi         ###   ########.fr       */
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

