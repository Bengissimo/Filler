/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:53:33 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/21 11:18:49 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_placeable(t_info *info, t_coord coord, t_maps **maps)
{
	int	row;
	int	col;
	int	found;

	found = FALSE;
	if (coord.y + info->piece_row > info->map_row
		|| coord.x + info->piece_col > info->map_col)
		return (FALSE);
	row = 0;
	while (row < info->piece_row)
	{
		col = 0;
		while (col < info->piece_col)
		{
			if (maps[coord.y + row][coord.x + col].pos == -2
			&& info->piece[row][col] == '*')
				return (FALSE);
			if (maps[coord.y + row][coord.x + col].pos == -1
			&& info->piece[row][col] == '*')
			{
				if (found)
					return (FALSE);
				found = TRUE;
			}
			col++;
		}
		row++;
	}	
	return (found);
}

void	put_piece(t_info *info, t_dist *list, t_maps **maps)
{
	unsigned int	i;
	unsigned int	size;

	size = info->dist_size;
	i = 0;
	while (i < size)
	{
		if (is_placeable(info, list[i].coord, maps))
		{
			ft_putnbr(list[i].coord.y);
			write(1, " ", 1);
			ft_putnbr(list[i].coord.x);
			write(1, "\n", 1);
			return ;
		}
		i++;
	}
	write(1, "0 0\n", 4);
}
