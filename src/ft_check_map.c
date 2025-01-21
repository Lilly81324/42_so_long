/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:40:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/21 18:47:03 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(char *fd)
{
	t_map	map;

	map.fd = ft_cooler_open(fd);
	if (map.fd < 0)
	{
		perror("ERROR Couldnt open map file");
		return (-1);
	}
	ft_get_height(&map);
	map.fd = ft_cooler_open(fd);
	ft_get_width(&map);
	printf("%i lines\n", map.lines);
	return (0);
}

// all 1 at the edges
// map must be rectangle
// >= 1 collictibles
// exactly 1 exit and 1 start
// valid path from start to all collectibles and exit
