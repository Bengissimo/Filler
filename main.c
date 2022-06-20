/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/20 16:02:41 by bkandemi         ###   ########.fr       */
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



int main(int ac, char **av)
{
	char		*line;
	t_info		info;
	t_dist	*list;
	t_maps		**maps;
	
	//int fd;
	if (ac != 1)
		return (EXIT_ERROR);
	list = NULL;
	maps = NULL;
	init_filler(&info);
	//fd = open("/Users/bkandemi/bkandemi_workspace/filler/output.txt", O_WRONLY | O_APPEND);
	while(TRUE)
	{
		if (get_next_line(0, &line) != 1)
			return (EXIT_ERROR);
		if (ft_strstr(line, "$$$ exec p"))
		{
			get_player_nb(&info, line, av[0]);
		}
		if (ft_strstr(line, "Plateau"))
		{
			if (!(get_map_size(&info, line)))
				return (EXIT_ERROR);
		}	
		if (ft_strstr(line, "    0"))
		{
			if (!info.player_nb || !info.map_col || !info.map_row)
				return(EXIT_ERROR);
			if (!maps)
				maps = init_maps(maps, info.map_row, info.map_col);
			if (!get_pos_map(&info, maps))
				return (EXIT_ERROR);
			if (info.is_new == FALSE)
				continue ;
			get_skip_map(&info, maps);
			get_dist_map(&info, maps);
			if (!list)
				list = init_list(&info);
			get_dist_list(list, &info, maps);
			sort_dist_list(list, &info);
		}
		if (ft_strstr(line, "Piece"))
		{
			get_piece_size(&info, line);
			get_piece(&info);
			put_piece(&info, list ,maps);
		}
		info.move_count++;
	}
	free_distance_list(list);
	//free_maps
	return (EXIT_SUCCESS);
}