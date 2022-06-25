/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/25 09:51:40 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h> //DELETE LATER

void	init_filler(t_filler *filler)
{
	filler->piece_row = 0;
	filler->piece_col = 0;
	filler->map_row = 0;
	filler->map_col = 0;
	filler->player_nb = 0;
	filler->dist_size = 0;
	filler->is_new = FALSE;
	filler->move_count = 0;
}

int	get_filler(char *line, t_filler *filler, char *name)
{
	if (ft_strstr(line, "$$$ exec p"))
		get_player_nb(filler, line, name);
	if (ft_strstr(line, "Plateau"))
	{
		if (!(get_map_size(filler, line)))
			return (EXIT_ERROR);
	}
	return (EXIT_SUCCESS);
}

int	get_maps(char *line, t_filler *filler, t_maps ***maps, t_dist **list)
{
	if (ft_strstr(line, "    0"))
	{
		if (!(filler->player_nb) || !(filler->map_col) || !(filler->map_row))
			return (EXIT_ERROR);
		if (!(*maps))
			*maps = init_maps(filler->map_row, filler->map_col);
		if (!get_pos_map(filler, line, *maps))
			return (EXIT_ERROR); //!!!
		if (filler->is_new == TRUE)
		{
			get_skip_map(filler, *maps);
			get_dist_map(filler, *maps);
			if (!(*list))
				*list = init_list(filler);
			get_dist_list(*list, filler, *maps);
			sort_dist_list(*list, filler);
		}
	}
	return (EXIT_SUCCESS);
}

int	place(char *line, t_filler *filler, t_maps **maps, t_dist *list)
{
	if (ft_strstr(line, "Piece"))
	{
		if (!get_piece_size(filler, line))
			return (EXIT_ERROR);
		if (!get_piece_shape(filler))
			return (EXIT_ERROR);
		if (!put_piece(filler, list, maps))
			return (EXIT_ERROR);
	}
	return (EXIT_SUCCESS);
}

//cleanup and exit fonksiyonu yaz ve return error kisminda onu cagir 

int	main(int ac, char **av)
{
	char		*line;
	t_filler		filler;
	t_dist		*list;
	t_maps		**maps;

	if (ac != 1)
		return (EXIT_ERROR);
	list = NULL;
	maps = NULL;
	init_filler(&filler);
	filler.player_name = av[0];
	while (TRUE)
	{
		if (get_next_line(0, &line) != 1)
			return (EXIT_ERROR);
		if (get_filler(line, &filler, av[0]) != EXIT_SUCCESS)
			return (EXIT_ERROR);
		if (get_maps(line, &filler, &maps, &list) != EXIT_SUCCESS)
			return (EXIT_ERROR);
		if (place(line, &filler, maps, list) != EXIT_SUCCESS)
			break ;
		filler.move_count++;
		ft_strdel(&line);
	}
	system("leaks bkandemi.filler > leaks.txt");
	return (clean_up(&filler, maps, list, line, EXIT_SUCCESS));
}
