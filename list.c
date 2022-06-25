/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:13:47 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/25 09:51:28 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_dist	*init_list(t_filler *filler)
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

void	get_dist_list(t_dist *list, t_filler *filler, t_maps **maps)
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
			if (maps[row][col].dist > 0)
			{
				list[i].dist = maps[row][col].dist;
				list[i].move = maps[row][col].move;
				list[i].coord.x = col;
				list[i].coord.y = row;
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

void	sort_dist_list(t_dist *list, t_filler *filler)
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
			if (list[j].dist > list[j + 1].dist
				|| (list[j].dist == list[j + 1].dist
					&& list[j].move < list[j + 1].move))
				has_swapped = swap(list + j, list + j + 1);
			j++;
		}
		if (!has_swapped)
			break ;
		i++;
	}	
}
