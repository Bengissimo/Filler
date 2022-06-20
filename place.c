/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:53:33 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/20 10:13:48 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_placeable(t_info *info, t_coord coord, t_maps **maps)
{
	int row;
	int col;
	int found;

	found = FALSE;
	if (coord.y + info->piece_row > info->map_row || coord.x + info->piece_col > info->map_col)
		return (FALSE);
	row = 0;
	while (row < info->piece_row)
	{
		col = 0;
		
		while (col < info->piece_col)
		{
			
			if (maps[coord.y + row][coord.x + col].pos == -2 && info->piece[row][col] == '*')
				return (FALSE);
			if (maps[coord.y + row][coord.x + col].pos == -1 && info->piece[row][col] == '*')
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

void	put_piece(t_info *info, t_distance *list, t_maps **maps)
{
	unsigned int	i;
	unsigned int	size;

	size = info->dist_size;

	//write(fd, "test\n", 5);
	i = 0;
	while (i < size)
	{
		/*ft_putnbr_fd(list[i].coord.y, fd);
		write(fd, " ", 1);
		ft_putnbr_fd(list[i].coord.x, fd);
		write(fd, "\n", 1);*/
		if (is_placeable(info, list[i].coord, maps))
		{
			//write(fd, "test3\n", 6);
			ft_putnbr(list[i].coord.y);
			//ft_putnbr_fd(list[i].coord.y ,fd);
			write(1, " ", 1);
			//write(fd, " ", 1);
			ft_putnbr(list[i].coord.x);
			//ft_putnbr_fd(list[i].coord.x ,fd);
			//write(fd, "\n", 1);
			write(1, "\n", 1);
			return ;
		}
		i++;
	}
	//write(fd, "0 0\n", 4);
	write(1, "0 0\n", 4);
}

