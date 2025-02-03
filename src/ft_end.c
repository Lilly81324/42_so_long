/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:19:31 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/03 15:52:22 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// destroys images and frees the image object
static void	ft_destroy_images(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img->wall);
	mlx_destroy_image(win->mlx, win->img->coin);
	mlx_destroy_image(win->mlx, win->img->player);
	mlx_destroy_image(win->mlx, win->img->exit);
	mlx_destroy_image(win->mlx, win->img->empty);
	mlx_destroy_image(win->mlx, win->img->up);
	mlx_destroy_image(win->mlx, win->img->right);
	mlx_destroy_image(win->mlx, win->img->down);
	mlx_destroy_image(win->mlx, win->img->left);
	free(win->img);
}

// called when programm should end
// closes windows, frees open things
// and then exits with 0
int	ft_end(t_win *win)
{
	ft_destroy_images(win);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	ft_free_caa(win->map->cont, 0);
	exit(0);
}
