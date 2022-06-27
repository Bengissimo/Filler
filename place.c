/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:32:49 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/27 12:13:56 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int	get_piece_shape(t_filler *fill)
{
	int		i;
	char	*line;

	fill->piece = (char **)malloc(sizeof(char *) * fill->piece_row);
	if (!fill->piece)
		return (FALSE);
	i = 0;
	while (i < fill->piece_row)
	{
		get_next_line(0, &line);
		if ((int)ft_strlen(line) != fill->piece_col)
			return (FALSE);
		fill->piece[i] = (char *)malloc(sizeof(char) * (fill->piece_col + 1));
		if (!fill->piece[i])
		{
			free_piece(fill->piece, i);
			return (FALSE);
		}
		ft_strcpy(fill->piece[i], line);
		ft_strdel(&line);
		i++;
	}
	return (TRUE);
}

static int	is_within_border(t_filler *filler, t_coord co)
{
	if (co.y + filler->piece_row > filler->map_row
		|| co.x + filler->piece_col > filler->map_col)
		return (FALSE);
	return (TRUE);
}

static int	is_placeable(t_filler *filler, t_coord co)
{
	t_coord	coord;
	int		found;

	found = FALSE;
	if (!is_within_border(filler, co))
		return (FALSE);
	coord.y = -1;
	while (++coord.y < filler->piece_row)
	{
		coord.x = -1;
		while (++coord.x < filler->piece_col)
		{
			if (filler->maps[co.y + coord.y][co.x + coord.x].pos == -2
				&& filler->piece[coord.y][coord.x] == '*')
				return (FALSE);
			if (filler->maps[co.y + coord.y][co.x + coord.x].pos == -1
				&& filler->piece[coord.y][coord.x] == '*')
			{
				if (found)
					return (FALSE);
				found = TRUE;
			}
		}
	}
	return (found);
}

int	put_piece(t_filler *filler)
{
	unsigned int	i;
	unsigned int	size;

	size = filler->dist_size;
	i = 0;
	while (i < size)
	{
		if (is_placeable(filler, filler->list[i].coord))
		{
			ft_putnbr(filler->list[i].coord.y);
			write(1, " ", 1);
			ft_putnbr(filler->list[i].coord.x);
			write(1, "\n", 1);
			free_piece(filler->piece, filler->piece_row);
			return (TRUE);
		}
		i++;
	}
	write(1, "0 0\n", 4);
	free_piece(filler->piece, filler->piece_row);
	return (FALSE);
}
