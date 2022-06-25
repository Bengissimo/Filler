/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:41:20 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/24 23:30:21 by bkandemi         ###   ########.fr       */
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

int	get_piece_size(t_filler *filler, char *line)
{
	char	*row;
	char	*col;

	row = ft_strchr(line, ' ') + 1;
	col = ft_strrchr(line, ' ') + 1;
	if (!row || !col)
		return (FALSE);
	filler->piece_row = ft_atoi(ft_strchr(line, ' ') + 1);
	filler->piece_col = ft_atoi(ft_strrchr(line, ' ') + 1);
	if (filler->piece_row <= 0 || filler->piece_col <= 0)
		return (FALSE);
	return (TRUE);
}

int	get_piece_shape(t_filler *filler)
{
	int		i;
	char	*line;

	filler->piece = (char **)malloc(sizeof(char *) * filler->piece_row);
	if (!filler->piece)
		return (FALSE);
	i = 0;
	while (i < filler->piece_row)
	{
		get_next_line(0, &line);
		filler->piece[i] = (char *)malloc(sizeof(char) * (filler->piece_col + 1));
		if (!filler->piece[i])
		{
			free_piece(filler->piece, i);
			return (FALSE);
		}
		ft_strcpy(filler->piece[i], line);
		ft_strdel(&line);
		i++;
	}
	return (TRUE);
}
