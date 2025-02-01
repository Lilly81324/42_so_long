/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:21:56 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/31 22:28:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// for D and R
// bottom right -> left, then up
static int	ft_find_en_dr(t_win *win, char type)
{
	int	y;
	int	x;

	y = win->map->height - 1;
	while (--y > 0)
	{
		x = win->map->width - 1;
		while (--x > 0)
		{
			if (win->map->cont[y][x] == type)
				ft_enemy_decis_bonus(win, x, y, type);
		}
	}
	return (0);
}

// for U and L
// top left -> right, then up
static int	ft_find_en_ul(t_win *win, char type)
{
	int	y;
	int	x;

	y = 0;
	while (++y < win->map->height - 1)
	{
		x = 0;
		while (++x < win->map->width - 1)
		{
			if (win->map->cont[y][x] == type)
				ft_enemy_decis_bonus(win, x, y, type);
		}
	}
	return (0);
}

// start bottom right	-> move left, then up
// start top left		-> move right, then down
// if enemy bounces from R to L then he gets another movement opportunity, when
// ft_find_en_ul(win, 'L'); is called
int	ft_enemy_bonus(t_win *win)
{
	ft_find_en_dr(win, 'D');
	ft_find_en_dr(win, 'R');
	ft_find_en_ul(win, 'U');
	ft_find_en_ul(win, 'L');
	ft_enemy_recharge_bonus(win);
	return (0);
}
