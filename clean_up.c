/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:49:00 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/22 22:32:24 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void free_maps(t_maps **maps, int index)
{
	int i;

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

void clean_up(t_info *info, t_maps **maps, t_dist *list, char *line)
{
	free_list(&list);
	if (maps)
		free_maps(maps, info->map_col);
	if (line)
		free(line);
}
