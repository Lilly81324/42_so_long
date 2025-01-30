/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:21:20 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/30 16:34:03 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key(int keycode, t_win *win)
{
	if (keycode == W_KEY)
		ft_move(win, -10);
	else if (keycode == A_KEY)
		ft_move(win, -01);
	else if (keycode == S_KEY)
		ft_move(win, 10);
	else if (keycode == D_KEY)
		ft_move(win, 01);
	else if (keycode == ESC_KEY)
		end(win);
	else
		ft_printf("|%i|\n", keycode);
	return (0);
}

int	ft_run_game(t_map *map)
{
	t_win	win;
	int		wid;
	int		hei;

	wid = map->width * SPRITE_SIZE;
	hei = map->height * SPRITE_SIZE;
	map->c_got = 0;
	map->moves = 0;
	if (ft_check_image_files() != 0)
		return (1);
	ft_printf("Moves: %i\n", map->moves);
	win.map = map;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, wid, hei, map->name);
	ft_make_images(&win);
	ft_display_map(&win);
	mlx_key_hook(win.win, key, &win);
	mlx_hook(win.win, 17, 0, end, &win);
	mlx_loop(win.mlx);
	return (0);
}
