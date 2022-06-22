/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/22 22:44:29 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h> //DELETE LATER

void	init_filler(t_info *info)
{
	info->piece_row = 0;
	info->piece_col = 0;
	info->map_row = 0;
	info->map_col = 0;
	info->player_nb = 0;
	info->dist_size = 0;
	info->is_new = FALSE;
	info->move_count = 0;
}

int	get_info(char *line, t_info *info, char *name)
{
	if (ft_strstr(line, "$$$ exec p"))
		get_player_nb(info, line, name);
	if (ft_strstr(line, "Plateau"))
	{
		if (!(get_map_size(info, line)))
			return (EXIT_ERROR);
	}
	return (EXIT_SUCCESS);
}

int	get_maps(char *line, t_info *info, t_maps ***maps, t_dist **list)
{
	if (ft_strstr(line, "    0"))
	{
		if (!(info->player_nb) || !(info->map_col) || !(info->map_row))
			return (EXIT_ERROR);
		if (!(*maps))
			*maps = init_maps(info->map_row, info->map_col);
		if (!get_pos_map(info, line, *maps))
		{
			free_maps(*maps, info->map_col);
			return (EXIT_ERROR);
		}
		if (info->is_new == TRUE)
		{
			get_skip_map(info, *maps);
			get_dist_map(info, *maps);
			if (!(*list))
				*list = init_list(info);
			get_dist_list(*list, info, *maps);
			sort_dist_list(*list, info);
		}
	}
	return (EXIT_SUCCESS);
}

int	place(char *line, t_info *info, t_maps **maps, t_dist *list)
{
	if (ft_strstr(line, "Piece"))
	{
		if (!get_piece_size(info, line))
			return (EXIT_ERROR);
		if (!get_piece_shape(info))
			return (EXIT_ERROR);
		put_piece(info, list, maps);
	}
	return (EXIT_SUCCESS);
}

//cleanup and exit fonksiyonu yaz ve return error kisminda onu cagir 

int	main(int ac, char **av)
{
	char		*line;
	t_info		info;
	t_dist		*list;
	t_maps		**maps;

	if (ac != 1)
		return (EXIT_ERROR);
	list = NULL;
	maps = NULL;
	init_filler(&info);
	info.player_name = av[0];
	while (TRUE)
	{
		if (get_next_line(0, &line) != 1)
			return (EXIT_ERROR);
		if (get_info(line, &info, av[0]) != EXIT_SUCCESS)
			return (EXIT_ERROR);
		if (get_maps(line, &info, &maps, &list) != EXIT_SUCCESS)
			return (EXIT_ERROR);
		if (place(line, &info, maps, list) != EXIT_SUCCESS)
			return (EXIT_ERROR);
		info.move_count++;
		free(line);
	}
	clean_up(&info, maps, list, line);
	return (EXIT_SUCCESS);
}
