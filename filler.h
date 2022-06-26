/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:12:51 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/26 15:39:13 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define EXIT_SUCCESS 0
# define EXIT_ERROR 1
# define TRUE 1
# define FALSE 0

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_dist
{
	t_coord			coord;
	unsigned int	dist;
	unsigned int	move;
}					t_dist;

typedef struct s_maps
{
	int				pos;
	unsigned int	dist;
	int				skip;
	unsigned int	move;
}					t_maps;

typedef struct s_filler
{
	int				player_nb;
	char			*player_name;
	char			me;
	char			foe;
	int				map_row;
	int				map_col;
	int				piece_row;
	int				piece_col;
	char			**piece;
	unsigned int	dist_size;
	unsigned int	move_count;
	int				is_new;
	t_maps			**maps;
	t_dist			*list;
}					t_filler;

/* main */
void	init_filler(t_filler *filler);
int		get_info(char *line, t_filler *filler, char *name);
int		set_game(char *line, t_filler *filler);
int		place(char *line, t_filler *filler);

/* get_info */
void	get_player_nb(t_filler *filler, char *line, char *name);
int		get_map_size(t_filler *filler, char *line);

/* set_game */
t_maps	**init_maps(int row_size, int col_size);
int		get_pos_map(t_filler *fill, char *line);
void	get_skip_map(t_filler *filler);
void	get_dist_map(t_filler *fill);
void	set_dist_list(t_filler *filler);

/* place */
int		get_piece_size(t_filler *filler, char *line);
int		get_piece_shape(t_filler *fill);
int		put_piece(t_filler *filler);

/* clean_up */
void	free_maps(t_maps **maps, int index);
void	free_list(t_dist **list);
void	free_piece(char **array, int size);
int		clean_up(t_filler *filler, char *line, int ret);

#endif
