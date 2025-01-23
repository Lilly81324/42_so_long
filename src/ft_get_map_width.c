/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:54:05 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/23 16:49:42 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 if the last and previous last lines are not equal
// since the last line can be abc\n\0 or abc\0 and both
// should be treated like they are equally long, this function
// adds +1 to the length so that they are counted equally
static int	ft_get_map_last_width(t_map *map, int index)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(map->cont[index]);
	while (map->cont[index][i] != '\0' && map->cont[index][i] != '\n')
		i++;
	if (map->cont[index][i] == '\0')
		len++;
	if (map->width != len)
		return (1);
	map->width = len;
	return (0);
}

// sets the width of the map object
// returns 0 nominally
// returns !0 in case of error
int	ft_get_map_width(t_map *map)
{
	int		i;
	char	*err;

	map->width = ft_strlen(map->cont[0]);
	i = 0;
	err = "ERROR Map is not rectangular (width)";
	while (i < map->height - 1)
	{
		if (map->width != (int)ft_strlen(map->cont[i]))
			return (ft_err_msg(err, 5));
		map->width = ft_strlen(map->cont[i]);
		i++;
	}
	if (ft_get_map_last_width(map, i) == 1)
		return (ft_err_msg(err, 5));
	map->width--;
	return (0);
}
