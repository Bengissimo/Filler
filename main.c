/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/05/26 16:56:22 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;
	char *player_info;
	char *map_size;
	int player_number;
	int row_size;
	int col_size;
	char **map;

	fd = open("/Users/bkandemi/bkandemi_workspace/filler/output.txt", O_WRONLY | O_APPEND);
	while (get_next_line(0, &line) > 0)
	{	
		if ((player_info = ft_strchr(line, 'p'))) //take player number
		{
			write(fd, player_info, ft_strlen(player_info));
			write(fd, "\n", 1);
			player_number = ft_atoi(player_info + 1);
			ft_putnbr_fd(player_number, fd);
			write(fd, "\n", 1);
		}
		if ((map_size = ft_strstr(line, "Plateau"))) //get map size !!!aynisini piece size bulmak icin de yap
		{
			write(fd, map_size, ft_strlen(map_size));
			write(fd, "\n", 1);
			row_size = ft_atoi(ft_strchr(line, ' ') + 1);
			col_size = ft_atoi(ft_strrchr(line, ' ') + 1);
			ft_putnbr_fd(row_size, fd);
			write(fd, "\n", 1);
			ft_putnbr_fd(col_size, fd);
			write(fd, "\n", 1);
		}
		
		
		
	
	}
	return (0);
}