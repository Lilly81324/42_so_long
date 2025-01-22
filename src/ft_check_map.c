/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:40:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 18:55:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// After get_map_height everyone is free and all files are closed
int	ft_check_map(t_map *map)
{
	int		fd;
	char	*first_line;

	fd = ft_cooler_open(map->name);
	if (fd < 0)
		return (1);
	first_line = ft_check_first_line(fd);
	if (first_line == NULL)
		return (errno);
	ft_get_map_height(map, fd, first_line);
	if (ft_get_map_cont(map) != 0)
		return (1);
	if (ft_get_map_width(map) != 0)
		return (1);
	if (ft_get_map_count(map) != 0)
		return (1);
	printf("Map: %s\n%ix%i\n", map->name, map->height, map->width);
	return (0);
}

// we know map exists, is accesible
// map starts immediately with content
// map is the same amount of characters wide

// we have maps dimension as well as local copy
// content has to be freed, nothing has to be closed

//TODO
// map consists entirely of valid characters
// map has specifications as in subject