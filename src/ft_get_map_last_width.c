/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_last_width.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:08:17 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 18:22:18 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 if the last and previous last lines are not equal
// since the last line can be abc\n\0 or abc\0 and both
// should be treated like they are equally long, this function
// adds +1 to the length so that they are counted equally
int	ft_get_map_last_width(t_map *map, int index)
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
