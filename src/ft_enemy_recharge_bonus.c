/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_recharge_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:15:17 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/03 18:28:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// capitalizes certain letters to signify their state
static void	ft_upper(t_win *win, int x, int y)
{
	char	type;

	type = win->map->cont[y][x];
	if (type == 'u')
		type = 'U';
	else if (type == 'd')
		type = 'D';
	else if (type == 'r')
		type = 'R';
	else if (type == 'l')
		type = 'L';
	else
		return ;
	win->map->cont[y][x] = type;
}

// makes enemies that used their turn bouncing ready again
void	ft_enemy_recharge_bonus(t_win *win)
{
	int	y;
	int	x;

	y = 0;
	while (++y < win->map->height - 1)
	{
		x = 0;
		while (++x < win->map->width - 1)
			ft_upper(win, x, y);
	}
}
