/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_decis_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:23:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/31 17:42:49 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// lets the enemy decide what they need to do
int	ft_enemy_decis(t_win *win, int posx, int posy, char type)
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
	printf("Enemy decides from %i %i to %i %i\n", posx, posy, x, y);
	if (win->map->cont[y][x] == 'P')
	{
		ft_end_kill(win);
		return (1);
	}
	if (win->map->cont[y][x] == '0')
		ft_enemy_move(win, posx, posy, type);
	else
		ft_enemy_bounce(win, posx, posy, type);
	return (0);
}
