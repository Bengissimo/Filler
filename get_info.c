/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:41:20 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/23 21:20:17 by bkandemi         ###   ########.fr       */
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

int	get_piece_size(t_info *info, char *line)
{
	char	*row;
	char	*col;

	row = ft_strchr(line, ' ') + 1;
	col = ft_strrchr(line, ' ') + 1;
	if (!row || !col)
		return (FALSE);
	info->piece_row = ft_atoi(ft_strchr(line, ' ') + 1);
	info->piece_col = ft_atoi(ft_strrchr(line, ' ') + 1);
	if (info->piece_row <= 0 || info->piece_col <= 0)
		return (FALSE);
	return (TRUE);
}

int	get_piece_shape(t_info *info)
{
	int		i;
	char	*line;

	info->piece = (char **)malloc(sizeof(char *) * info->piece_row);
	if (!info->piece)
		return (FALSE);
	i = 0;
	while (i < info->piece_row)
	{
		get_next_line(0, &line);
		info->piece[i] = (char *)malloc(sizeof(char) * (info->piece_col + 1));
		if (!info->piece[i])
		{
			free_piece(&(info->piece), i);
			return (FALSE);
		}
		ft_strcpy(info->piece[i], line);
		ft_strdel(&line);
		i++;
	}
	return (TRUE);
}
