/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:54:30 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/30 17:36:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns the number of collectables in the current map
static int	ft_count_collectibles(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->cont[i][j] == 'C')
				count++;
		}
	}
	return (count);
}

// get the x and y coordinate of player when starting
static void	ft_get_player_start_pos(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->p_x = -1;
	map->p_y = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->cont[i][j] == 'P')
			{
				map->p_y = i;
				map->p_x = j;
				return ;
			}
		}
	}
}

static void	ft_flood_fill(t_map *map, t_map_cnt *map_c, int x, int y)
{
	if (map->cont[y][x] == 'X' || map->cont[y][x] == '1')
		return ;
	if (map->cont[y][x] == 'E')
	{
		map_c->e++;
		map->cont[y][x] = 'X';
		return ;
	}
	if (map->cont[y][x] == 'C')
		map_c->c++;
	map->cont[y][x] = 'X';
	ft_flood_fill(map, map_c, x +1, y);
	ft_flood_fill(map, map_c, x -1, y);
	ft_flood_fill(map, map_c, x, y +1);
	ft_flood_fill(map, map_c, x, y -1);
}

// Checks if all Collectibles can be reached from the player
// and if the exit can then be reached
// returns 0 if yes
int	ft_check_map_path(t_map *map)
{
	int			count;
	int			x;
	int			y;
	t_map_cnt	map_c;
	t_map		copy;

	map_c.c = 0;
	map_c.e = 0;
	count = ft_count_collectibles(map);
	ft_get_player_start_pos(map);
	copy.cont = ft_copy_caa(map->cont);
	ft_flood_fill(&copy, &map_c, map->p_x, map->p_y);
	ft_free_caa(copy.cont, 0);
	if (map_c.e != 1)
		return (ft_err_msg("Not enough exits reachable", 5));
	if (map_c.c != count)
		return (ft_err_msg("Not all collectables reachable", 5));
	return (0);
}

// map->cont[y][x] is how to use x and y
// count collectible number
// get position of player
// floodfill starting from player
// if floodfill can find all collectibles and the exit
