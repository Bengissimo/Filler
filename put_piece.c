/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:53:33 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/23 21:04:10 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_within_border(t_info *info, t_coord co)
{
	if (co.y + info->piece_row > info->map_row
		|| co.x + info->piece_col > info->map_col)
		return (FALSE);
	return (TRUE);
}

static int	is_placeable(t_info *info, t_coord co, t_maps **maps)
{
	t_coord	coord;
	int		found;

	found = FALSE;
	if (!is_within_border(info, co))
	{
		//ft_free_array(info->piece, info->piece_col);
		return (FALSE);
	}
	coord.y = -1;
	while (++coord.y < info->piece_row)
	{
		coord.x = -1;
		while (++coord.x < info->piece_col)
		{
			if (maps[co.y + coord.y][co.x + coord.x].pos == -2
				&& info->piece[coord.y][coord.x] == '*')
				{
					//ft_free_array(info->piece, info->piece_col);
					return (FALSE);
				}
			if (maps[co.y + coord.y][co.x + coord.x].pos == -1
				&& info->piece[coord.y][coord.x] == '*')
			{
				if (found)
				{
					return (FALSE);
				}
				found = TRUE;
			}
		}
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
			//
			return ;
		}
		
		i++;
	}
	//
	write(1, "0 0\n", 4);
}
