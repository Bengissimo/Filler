/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:42:39 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/26 15:40:35 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player_nb(t_filler *filler, char *line, char *name)
{
	char	*player_filler;

	if (filler->player_nb != 0)
		return ;
	if (!ft_strstr(line, name))
		return ;
	player_filler = ft_strchr(line, 'p');
	if (!player_filler)
		return ;
	filler->player_nb = ft_atoi(player_filler + 1);
	if (!filler->player_nb)
		return ;
	if (filler->player_nb == 1)
	{
		filler->me = 'O';
		filler->foe = 'X';
	}
	else if (filler->player_nb == 2)
	{
		filler->me = 'X';
		filler->foe = 'O';
	}
}

int	get_map_size(t_filler *filler, char *line)
{
	char	*row;
	char	*col;

	row = ft_strchr(line, ' ') + 1;
	col = ft_strrchr(line, ' ') + 1;
	if (!row || !col)
		return (FALSE);
	filler->map_row = ft_atoi(row);
	filler->map_col = ft_atoi(col);
	if (filler->map_row <= 0 || filler->map_col <= 0)
		return (FALSE);
	return (TRUE);
}
