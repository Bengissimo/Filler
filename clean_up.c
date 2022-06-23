/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:49:00 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/23 15:02:52 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void free_maps(t_maps **maps, int index)
{
	int i;

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

void free_list(t_dist **list)
{
	if (list && *list)
	{
		free(*list);
		*list = NULL;
	}
}

void	free_piece(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

int clean_up(t_info *info, t_maps **maps, t_dist *list, char *line, int ret)
{
	free_list(&list);
	free_piece(info->piece);
	free_maps(maps, info->map_row);
	ft_strdel(&line);
	return (ret);
}
