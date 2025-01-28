/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:18:29 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/28 17:18:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_images(t_win *win)
{
	t_img *images;
	int	si;

	si = SPRITE_SIZE;
	images = (t_img *)malloc(sizeof(t_img));
	images->wall = mlx_xpm_file_to_image(win->mlx, "wall.xpm", &si, &si);
	images->empty = mlx_xpm_file_to_image(win->mlx, "free.xpm", &si, &si);
	images->coin = mlx_xpm_file_to_image(win->mlx, "apple.xpm", &si, &si);
	images->player = mlx_xpm_file_to_image(win->mlx, "player.xpm", &si, &si);
	images->exit = mlx_xpm_file_to_image(win->mlx, "exit.xpm", &si, &si);
	win->img = images;
}
