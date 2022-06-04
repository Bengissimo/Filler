/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:12:51 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/04 22:26:59 by bkandemi         ###   ########.fr       */
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
	t_coord		foe_curr;
	t_coord		my_curr;
	t_coord		foe_prev;
	t_coord		my_prev;
}				t_info;

typedef struct	s_way
{
	int			x;
	int			y;
	int			up;
	int			up_right;
	int			up_left;
	int			down;
	int			down_right;
	int			down_left;
	int			right;
	int			left;
}				t_way;




# endif