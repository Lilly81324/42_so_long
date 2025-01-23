/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_edges.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:32:37 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/23 13:32:37 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_edges(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
	{
		if (map->cont[0][i] != '1')
			return (1);
	}
	i = 0;
	while (++i < map->height - 1)
	{
		if (map->cont[i][0] != '1')
			return (1);
		if (map->cont[i][map->width - 1] != '1')
			return (1);
	}
	i = -1;
	while (++i < map->width)
	{
		if (map->cont[map->height - 1][i] != '1')
			return (1);
	}
	return (0);
}
