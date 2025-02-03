/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bounce_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:02:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/03 18:26:41 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// makes the enemy 'bounce' off an obstacle in thier way
// consumes that enemies turn and changes their type
// into the opposite direction
void	ft_enemy_bounce_bonus(t_win *win, int x, int y, char type)
{
	void	*img;
	int		si;

	si = SPRITE_SIZE;
	if (type == 'U')
		type = 'd';
	else if (type == 'D')
		type = 'u';
	else if (type == 'R')
		type = 'l';
	else if (type == 'L')
		type = 'r';
	win->map->cont[y][x] = type;
	img = ft_cont_to_img(win, type);
	mlx_put_image_to_window(win->mlx, win->win, img, x * si, y * si);
}
