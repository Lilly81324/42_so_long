/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:54:05 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 18:23:49 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// sets the width of the map object
// returns 0 nominally
// returns !0 in case of error
int	ft_get_map_width(t_map *map)
{
	int		i;
	int		wrong;

	map->width = ft_strlen(map->cont[0]);
	i = 0;
	wrong = 0;
	while (i < map->height - 1)
	{
		if (map->width != (int)ft_strlen(map->cont[i]))
			wrong = 1;
		map->width = ft_strlen(map->cont[i]);
		i++;
	}
	if (ft_get_map_last_width(map, i) == 1)
		wrong = 1;
	map->width--;
	if (wrong == 1)
	{
		errno = 5;
		perror("ERROR Map is not rectangular (width)");
		return (5);
	}
	return (0);
}
