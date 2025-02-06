/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:31:31 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/06 14:08:27 by sikunne          ###   ########.fr       */
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
	map->enemies = 0;
	map->other = 0;
}

// Checks for valid amount of characters in map
static int	ft_check_valid_chars(t_map_cnt *map_c)
{
	errno = 5;
	if (map_c->one < 1)
		return (ft_err_msg("Not enough 1s in map", 5));
	else if (map_c->p != 1)
		return (ft_err_msg("Wrong amount of players, exactly 1", 5));
	else if (map_c->c < 1)
		return (ft_err_msg("Not enough collectibles, min is 1", 5));
	else if (map_c->e != 1)
		return (ft_err_msg("Wrong amount of exits, exactly 1", 5));
	else if (map_c->other > 0)
		return (ft_err_msg("Invalid character found in map", 5));
	else
		return (0);
}

// counts the respective counter up for the given coords
static void	ft_add_map_c(t_map *map, t_map_cnt *map_c, int i, int j)
{
	if (map->cont[i][j] == '1')
		map_c->one++;
	else if (map->cont[i][j] == 'P')
		map_c->p++;
	else if (map->cont[i][j] == 'C')
		map_c->c++;
	else if (map->cont[i][j] == 'E')
		map_c->e++;
	else if (map->cont[i][j] == '0')
		return ;
	else
		map_c->other++;
	return ;
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
			ft_add_map_c(map, &map_c, i, j);
	}
	map->e_tot = map_c.enemies;
	map->c_tot = map_c.c;
	return (ft_check_valid_chars(&map_c));
}
