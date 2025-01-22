/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:31:31 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 18:53:51 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Saves the amount of each character in the map
// into an object which then gets checked for standards
// returns 0 if nominal
// returns 1 if error
int	ft_get_map_count(t_map *map)
{
	t_map_cnt	map_c;
	int			i;
	int			j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->cont[i][j] == '0')
				map_c.zero++;
			else if (map->cont[i][j] == '1')
				map_c.one++;
			else if (map->cont[i][j] == 'P')
				map_c.p++;
			else if (map->cont[i][j] == 'C')
				map_c.c++;
			else if (map->cont[i][j] == 'E')
				map_c.e++;
			else
				map_c.other++;
		}
	}
	return (ft_check_valid_chars(&map_c));
}
