/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:41:20 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/20 10:41:49 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_player_nb(t_info *info, char *line)
{
	char	*player_info;

	player_info = ft_strchr(line, 'p');
	if (!player_info)
		return (FALSE);
	info->player_nb = ft_atoi(player_info + 1);
	if (info->player_nb == 1)
	{
		info->me = 'O';
		info->foe = 'X';
		return (TRUE);
	}
	else if (info->player_nb == 2)
	{
		info->me = 'X';
		info->foe = 'O';
		return (TRUE);
	}
	return (FALSE);
}