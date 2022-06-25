/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:53:33 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/25 10:26:48 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
