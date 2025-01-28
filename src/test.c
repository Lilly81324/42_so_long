/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:59:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/28 16:45:52 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:21:20 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/28 15:32:10 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end(t_win *win)
{
	mlx_destroy_image(win->mlx, win->map->imgs);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
}

// returns 0 if movement in the direction is possible
// returns 1 if invalid or not possible
// dir -> change in coords:
// W: -10 = -y, S: +10 = +y
// A: -01 = -x, D: +01 = +x
int ft_move(t_win *win, int dir)
{
	int	x;
	int	y;

	x = win->map->p_x;
	y = win->map->p_y + (dir / 10);
	win->map->p_x = x;
	win->map->p_y = y;
	mlx_put_image_to_window(win->mlx, win->win, win->map->imgs, x * 64, y * 64);
	return (0);
}

int	key(int keycode, t_win *win)
{
	if (keycode == W_KEY)
		ft_move(win, -10);
	else if (keycode == S_KEY)
		ft_move(win, 10);
	else if (keycode == ESC_KEY)
		end(win);
	else
		printf("|%i|\n", keycode);
	return (0);
}

int	ft_run_game(t_map *map)
{
	t_win	win;
	int		size;
	t_img	img;

	size = 64;
	win.map = map;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, map->width * SPRITE_SIZE, map->height\
							 * SPRITE_SIZE, "So_long");
	img = ft_make_images(&win);
	mlx_key_hook(win.win, key, &win);
	mlx_loop(win.mlx);
	return (0);
}

//  mlx_destroy_window(win->mlx, win->win);
// 	mlx_destroy_display(win->mlx);
// 	free(win->mlx);

void	ft_make_images(t_win *win)
{
	t_img *images;
	int	si;

	si = SPRITE_SIZE;
	images->wall = mlx_xpm_file_to_image(win->mlx, "wall.xpm", &si, &si);
	images->empty = mlx_xpm_file_to_image(win->mlx, "free.xpm", &si, &si);
	images->coin = mlx_xpm_file_to_image(win->mlx, "apple.xpm", &si, &si);
	images->player = mlx_xpm_file_to_image(win->mlx, "player.xpm", &si, &si);
	images->exit = mlx_xpm_file_to_image(win->mlx, "exit.xpm", &si, &si);
	win->img = images
}

int main(void)
{
	t_map map;
	t_img img;

	map.height = 10;
	map.width = 10;
	map.p_x = 5;
	map.p_y = 5;
	ft_run_game(&map);
	return (0);
}