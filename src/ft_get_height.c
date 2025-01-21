/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_height.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:55:28 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/21 18:55:22 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// gets the amount of lines of content that are in the map
int	ft_get_height(t_map *map)
{
	int		joever;
	char	*line;

	joever = 0;
	line = get_next_line(map->fd);
	map->lines = 0;
	while (line != NULL)
	{
		if (map->lines > 0 && line[0] == '\n')
			joever = 1;
		if (line[0] != '\n' && joever == 0)
			map->lines++;
		free(line);
		line = get_next_line(map->fd);
	}
	if (line != NULL)
		free(line);
	close(map->fd);
	return (0);
}
