/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/27 10:56:00 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

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
	filler->maps = NULL;
	filler->list = NULL;
}

int	get_info(char *line, t_filler *filler, char *name)
{
	if (ft_strstr(line, "$$$ exec p"))
		get_player_nb(filler, line, name);
	if (ft_strstr(line, "Plateau"))
	{
		if (!get_map_size(filler, line))
			return (EXIT_ERROR);
	}
	return (EXIT_SUCCESS);
}

int	set_game(char *line, t_filler *filler)
{
	if (ft_strstr(line, "    0"))
	{
		if (!(filler->player_nb) || !(filler->map_col) || !(filler->map_row))
			return (EXIT_ERROR);
		if (!(filler->maps))
			filler->maps = init_maps(filler->map_row, filler->map_col);
		if (!get_pos_map(filler, line))
			return (EXIT_ERROR);
		if (filler->is_new == TRUE)
		{
			get_skip_map(filler);
			get_dist_map(filler);
			set_dist_list(filler);
		}
	}
	return (EXIT_SUCCESS);
}

int	place(char *line, t_filler *filler)
{
	if (ft_strstr(line, "Piece"))
	{
		if (!get_piece_size(filler, line))
			return (EXIT_ERROR);
		if (!get_piece_shape(filler))
			return (EXIT_ERROR);
		if (!put_piece(filler))
			return (EXIT_ERROR);
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	char		*line;
	t_filler	filler;

	if (ac != 1)
		return (EXIT_ERROR);
	init_filler(&filler);
	filler.player_name = av[0];
	while (TRUE)
	{
		if (get_next_line(0, &line) != 1)
			return (clean_up(&filler, line, EXIT_ERROR));
		if (get_info(line, &filler, av[0]) != EXIT_SUCCESS)
			return (clean_up(&filler, line, EXIT_ERROR));
		if (set_game(line, &filler) != EXIT_SUCCESS)
			return (clean_up(&filler, line, EXIT_ERROR));
		if (place(line, &filler) != EXIT_SUCCESS)
			break ;
		filler.move_count++;
		ft_strdel(&line);
	}
	return (clean_up(&filler, line, EXIT_SUCCESS));
}
