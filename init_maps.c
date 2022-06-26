/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:28:46 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/26 15:29:09 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_maps_values(t_maps ***maps, int i, int j)
{
	(*maps)[i][j].pos = 0;
	(*maps)[i][j].skip = FALSE;
	(*maps)[i][j].move = 0;
}

t_maps	**init_maps(int row_size, int col_size)
{
	int		i;
	int		j;
	t_maps	**maps;

	maps = (t_maps **)malloc(sizeof(t_maps *) * row_size);
	if (!maps)
		return (NULL);
	i = 0;
	while (i < row_size)
	{
		maps[i] = (t_maps *)malloc(sizeof(t_maps) * col_size);
		if (!(maps[i]))
		{
			free_maps(maps, i);
			return (NULL);
		}
		j = 0;
		while (j < col_size)
		{
			set_maps_values(&maps, i, j);
			j++;
		}
		i++;
	}
	return (maps);
}
