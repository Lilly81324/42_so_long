/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:26:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/03 18:27:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// moves an enemy from fx, fy to tx ty
void	ft_enemy_move_bonus(t_win *win, int fx, int fy, char type)
{
	void	*img;
	int		si;
	int		tx;
	int		ty;

	tx = fx;
	ty = fy;
	if (type == 'U')
		ty--;
	else if (type == 'R')
		tx++;
	else if (type == 'L')
		tx--;
	else
		ty++;
	si = SPRITE_SIZE;
	win->map->cont[fy][fx] = '0';
	img = ft_cont_to_img(win, '0');
	mlx_put_image_to_window(win->mlx, win->win, img, fx * si, fy * si);
	win->map->cont[ty][tx] = type;
	img = ft_cont_to_img(win, type);
	mlx_put_image_to_window(win->mlx, win->win, img, tx * si, ty * si);
}
