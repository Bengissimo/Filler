/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:12:51 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/08 19:05:52 by bkandemi         ###   ########.fr       */
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
	int				dist;
}					t_distance;

typedef struct	s_info
{
	int			player_nb;
	char		me;
	char		foe;
	int			map_row;
	int			map_col;
	int			piece_row;
	int			piece_col;
	int			**map;
	char		**piece;
}				t_info;

t_distance	*parse_distance_list(t_info *info);
void	sort_distance_list(t_distance *list);
void	print_dist_list(t_distance *list, int fd);


# endif