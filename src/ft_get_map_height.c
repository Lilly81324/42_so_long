/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:55:28 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 16:27:54 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// gets the amount of lines of content that are in the map
// and saves them in map.height
// closes the file, since it needs to read through
void	ft_get_map_height(t_map *map, int fd, char *first_line)
{
	int		joever;
	char	*line;

	joever = 0;
	line = first_line;
	map->height = 0;
	while (line != NULL && line[0] != '\n')
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
