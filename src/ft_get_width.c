/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:38:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/21 18:55:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// doesnt work
// gets the amount of lines of content that are in the map
int	ft_get_width(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	map->width = -1;
	while (line != NULL && line[0] == '\n')
	{
		free(line);
		line = get_next_line(map->fd);
	}
	while (line != NULL && line[0] != '\n')
	{
		if (map->width != -1 && map->width != (int)ft_strlen(line))
		{
			printf("ODD\n");
			free(line);
			return (-1);
		}
		map->width = ft_strlen(line);
		printf("Breite = %i\n", map->width);
		free(line);
		line = get_next_line(map->fd);
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(map->fd);
	}
	close(map->fd);
	return (0);
}
