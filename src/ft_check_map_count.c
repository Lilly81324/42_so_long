/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:31:31 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/23 16:33:06 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Pretty obvious
static void	ft_set_map_c(t_map_cnt *map)
{
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->one = 0;
	map->other = 0;
}

// Checks for valid amount of characters in map
static int	ft_check_valid_chars(t_map_cnt *map_c)
{
	errno = 5;
	if (map_c->one < 1)
		perror("ERROR Not enough 1s in map");
	else if (map_c->p != 1)
		perror("ERROR Wrong amount of players, exactly 1");
	else if (map_c->c < 1)
		perror("ERROR Not enough collectibles, min is 1");
	else if (map_c->e != 1)
		perror("ERROR Wrong amount of exits, exactly 1");
	else if (map_c->other > 0)
		perror("ERROR Invalid character found in map");
	else
		return (0);
	return (1);
}

// Saves the amount of each character in the map
// into an object which then gets checked for standards
// returns 0 if nominal
// returns 1 if error
int	ft_check_map_count(t_map *map)
{
	t_map_cnt	map_c;
	int			i;
	int			j;

	i = -1;
	ft_set_map_c(&map_c);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->cont[i][j] == '1')
				map_c.one++;
			else if (map->cont[i][j] == 'P')
				map_c.p++;
			else if (map->cont[i][j] == 'C')
				map_c.c++;
			else if (map->cont[i][j] == 'E')
				map_c.e++;
			else if (map->cont[i][j] != '0')
				map_c.other++;
		}
	}
	return (ft_check_valid_chars(&map_c));
}
