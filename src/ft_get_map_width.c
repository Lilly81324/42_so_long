/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:54:05 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 17:59:23 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// sets the width of the map object
// returns 0 nominally
// returns !0 in case of error
int	ft_get_map_width(t_map *map)
{
	int		i;

	map->width = ft_strlen(map->cont[0]);
	i = 0;
	while (i < map->height)
	{
		if (map->width != (int)ft_strlen(map->cont[i]))
		{
			errno = 5;
			perror("ERROR Map is not rectangular (width)");
			return (5);
		}
		map->width = ft_strlen(map->cont[i]);
		i++;
	}
	return (0);
}
