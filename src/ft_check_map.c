/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:40:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/23 15:14:52 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Open the file and check the first line
// Then continue checking the rest of the map and count the height
// Then close the map and read its contents into the map object
// Read the width of each line and check if one is longer than the rest
// Count the different characters that are in the map and check them
// Check that all the edges are 1s
// return 0 if map is okay
// otherwise return 1
int	ft_check_map(t_map *map)
{
	int		fd;
	char	*first_line;

	fd = ft_cooler_open(map->name);
	if (fd != 0)
		return (1);
	first_line = ft_check_first_line(fd);
	if (first_line == NULL)
		return (1);
	ft_get_map_height(map, fd, first_line);
	if (ft_get_map_cont(map) != 0)
		return (1);
	if (ft_get_map_width(map) != 0)
		return (1);
	if (ft_check_map_count(map) != 0)
		return (1);
	if (ft_check_map_edges(map) != 0)
		return(1);
	return (0);
}
