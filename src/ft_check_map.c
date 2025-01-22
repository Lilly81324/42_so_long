/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:40:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 17:56:03 by sikunne          ###   ########.fr       */
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
	printf("Map: %s\n%ix%i\nContent:\n", map->name, map->height, map->width);
	return (0);
}

// all 1 at the edges
// map must be rectangle
// >= 1 collictibles
// exactly 1 exit and 1 start
// valid path from start to all collectibles and exit
