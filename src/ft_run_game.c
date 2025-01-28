/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:21:20 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/28 14:17:07 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(ft_free_caa(win->map->cont, 0));
}

void	ft_move_player(t_win *win, int x, int y)
{
	win->map->cont[win->map->p_y][win->map->p_x] = '0';
	win->map->cont[y][x] = 'P';
	win->map->p_x = x;
	win->map->p_y = y;
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

	x = win->map->p_x + (dir % 10);
	y = win->map->p_y + (dir / 10);
	if (win->map->cont[y][x] == '1')
		return (1);
	else if (win->map->cont[y][x] == 'E' && win->map->c_got != win->map->c_tot)
		return (1);
	else if (win->map->cont[y][x] == 'E')
		end(win);
	else if (win->map->cont[y][x] == 'C')
		win->map->c_got++;
	ft_move_player(win, x, y);
	ft_make_img_map(win);
	return (0);
}


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
		printf("|%i|\n", keycode);
	return (0);
}

int	ft_run_game(t_map *map)
{
	t_win	win;

	map->c_got = 0;
	win.map = map;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, map->width * SPRITE_SIZE, map->height\
							 * SPRITE_SIZE, "So_long");
	ft_make_img_map(&win);
	mlx_key_hook(win.win, key, &win);
	mlx_mouse_hook(win.win, key, &win);
	mlx_loop(win.mlx);
	return (0);
}

//  mlx_destroy_window(win->mlx, win->win);
// 	mlx_destroy_display(win->mlx);
// 	free(win->mlx);