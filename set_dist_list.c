/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:13:47 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/26 15:31:16 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_dist	*init_list(t_filler *filler)
{
	unsigned int	size;
	unsigned int	i;
	t_dist			*list;

	size = filler->map_col * filler->map_row;
	list = (t_dist *)malloc(sizeof(t_dist) * size);
	if (!list)
		return (NULL);
	i = 0;
	while (i < size)
	{
		list[i].dist = filler->map_col + filler->map_row;
		list[i].move = 0;
		i++;
	}
	return (list);
}

static void	get_dist_list(t_filler *filler)
{
	int				row;
	int				col;
	unsigned int	i;

	row = 0;
	i = 0;
	while (row < filler->map_row)
	{
		col = 0;
		while (col < filler->map_col)
		{
			if (filler->maps[row][col].dist > 0)
			{
				filler->list[i].dist = filler->maps[row][col].dist;
				filler->list[i].move = filler->maps[row][col].move;
				filler->list[i].coord.x = col;
				filler->list[i].coord.y = row;
				i++;
			}
			col++;
		}
		row++;
	}
	filler->dist_size = i;
}

static int	swap(t_dist *list1, t_dist *list2)
{
	t_dist	temp;

	temp = *list1;
	*list1 = *list2;
	*list2 = temp;
	return (TRUE);
}

static void	sort_dist_list(t_filler *filler)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	int				has_swapped;

	has_swapped = FALSE;
	i = 0;
	size = filler->dist_size;
	if (!size)
		return ;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (filler->list[j].dist > filler->list[j + 1].dist
				|| (filler->list[j].dist == filler->list[j + 1].dist
					&& filler->list[j].move < filler->list[j + 1].move))
				has_swapped = swap(filler->list + j, filler->list + j + 1);
			j++;
		}
		if (!has_swapped)
			break ;
		i++;
	}	
}

void	set_dist_list(t_filler *filler)
{
	if (!(filler->list))
		filler->list = init_list(filler);
	get_dist_list(filler);
	sort_dist_list(filler);
}
