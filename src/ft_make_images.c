/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:18:29 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/06 14:29:37 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_images(t_win *win)
{
	t_img	*img;
	int		si;

	si = SPRITE_SIZE;
	img = (t_img *)malloc(sizeof(t_img));
	img->wall = mlx_xpm_file_to_image(win->mlx, WALL_TEXTURE, &si, &si);
	img->empty = mlx_xpm_file_to_image(win->mlx, FLOOR_TEXTUE, &si, &si);
	img->coin = mlx_xpm_file_to_image(win->mlx, COIN_TEXTURE, &si, &si);
	img->player = mlx_xpm_file_to_image(win->mlx, PLAYER_TEXTURE, &si, &si);
	img->exit = mlx_xpm_file_to_image(win->mlx, EXIT_TEXTURE, &si, &si);
	img->up = mlx_xpm_file_to_image(win->mlx, PLAYER_TEXTURE, &si, &si);
	img->right = mlx_xpm_file_to_image(win->mlx, PLAYER_TEXTURE, &si, &si);
	img->down = mlx_xpm_file_to_image(win->mlx, PLAYER_TEXTURE, &si, &si);
	img->left = mlx_xpm_file_to_image(win->mlx, PLAYER_TEXTURE, &si, &si);
	win->img = img;
}
