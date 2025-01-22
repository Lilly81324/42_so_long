/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_cont.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:49:06 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 17:56:34 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// opens the map by name
// checks if openable RETUNS -1 if not
// reads map file into map object
// closes map file
int	ft_get_map_cont(t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	fd = ft_cooler_open(map->name);
	if (fd < 0)
		return (1);
	map->cont = (char **)malloc((map->height + 1) * sizeof(char *));
	while (++i < map->height)
		map->cont[i] = get_next_line(fd);
	map->cont[i] = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
