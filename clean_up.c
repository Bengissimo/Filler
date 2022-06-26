/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:49:00 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/26 14:24:21 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_maps(t_maps **maps, int index)
{
	int	i;

	if (!maps)
		return ;
	i = 0;
	while (i < index)
	{
		free(maps[i]);
		i++;
	}
	free(maps);
}

void	free_list(t_dist **list)
{
	if (list && *list)
	{
		free(*list);
		*list = NULL;
	}
}

void	free_piece(char **array, int size)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < size)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

int	clean_up(t_filler *filler, char *line, int ret)
{
	free_list(&(filler->list));
	free_maps(filler->maps, filler->map_row);
	ft_strdel(&line);
	return (ret);
}
