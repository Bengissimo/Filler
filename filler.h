/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:12:51 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/18 11:33:28 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef	struct		s_distance
{
	t_coord			coord;
	unsigned int	dist;
}					t_distance;

typedef struct		s_info
{
	int		player_nb;
	char	me;
	char	foe;
	int		map_row;
	int		map_col;
	int		piece_row;
	int		piece_col;
	char	**piece;
	unsigned int	dist_size;
	unsigned int	move_count;
	int		is_new;
}					t_info;

typedef struct		s_maps
{
	int				pos;
	unsigned int	dist;
	int				skip;
	unsigned int	move;
}					t_maps;

void	parse_distance_list(t_distance *list, t_info *info, t_maps **maps);
void	sort_distance_list(t_distance *list, t_info *info);
void print_dist_list(t_distance *list, int fd, t_info *info); //del
//void	put_piece(t_info *info, t_distance *list);
void	free_distance_list(t_distance *list);

t_maps	**init_maps(t_maps **maps, int row_size, int col_size);
void	parse_map(t_info *info, t_maps **maps);
int	min_distance(t_info *info, t_maps **maps, t_coord coord);
int	check_if_nearby_free(t_info *info, t_maps **maps, t_coord coord);
void set_dist(t_info *info, t_maps **maps);
void	put_piece(t_info *info, t_distance *list, t_maps **maps);

void	set_skip(t_maps **maps, t_info *info);

t_distance	*init_list(t_info *info);







# endif