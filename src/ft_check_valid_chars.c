/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:43:28 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 18:52:52 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks for valid amount of characters in map
int	ft_check_valid_chars(t_map_cnt *map_c)
{
	errno = 5;
	if (map_c->one < 1)
		perror("Not enough 1s in map");
	else if (map_c->p != 1)
		perror("Wrong amount of plazers, exactly 1");
	else if (map_c->c < 1)
		perror("Not enought collectibles, min is 1");
	else if (map_c->e != 1)
		perror("Wrong amount of exits, exactly 1");
	else if (map_c->other > 0)
		perror("Invalid character found in map");
	else
		return (0);
	return (1);
}
