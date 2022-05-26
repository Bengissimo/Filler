/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:57 by bkandemi          #+#    #+#             */
/*   Updated: 2022/05/25 19:35:21 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int main(void)
{
	int gnl;
	char *line;

	while ((gnl = get_next_line(0, &line)) > 0)
	{
		printf("%s\n", line);
	}
	return (0);
}