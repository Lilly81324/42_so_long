/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bounce_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:02:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/31 17:14:34 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// makes the enemy 'bounce' off an obstacle in thier way
// consumes that enemies turn and changes their type
// into the opposite direction
void	ft_enemy_bounce(t_win *win, int x, int y, char type)
{
	if (type == 'U')
		type = 'd';
	else if (type == 'D')
		type = 'u';
	else if (type == 'R')
		type = 'l';
	else if (type == 'L')
		type = 'r';
	win->map->cont[y][x] = type;
}