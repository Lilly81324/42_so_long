/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_decis_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:23:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/31 20:51:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// lets the enemy decide what they need to do
int	ft_enemy_decis_bonus(t_win *win, int posx, int posy, char type)
{
	int	x;
	int	y;

	x = posx;
	y = posy;
	if (type == 'U')
		y--;
	else if (type == 'R')
		x++;
	else if (type == 'L')
		x--;
	else 
		y++;
	if (win->map->cont[y][x] == 'P')
	{
		ft_end_kill_bonus(win);
		return (1);
	}
	if (win->map->cont[y][x] == '0')
		ft_enemy_move_bonus(win, posx, posy, type);
	else
		ft_enemy_bounce_bonus(win, posx, posy, type);
	return (0);
}
