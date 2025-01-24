/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:21:20 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/24 18:16:20 by sikunne          ###   ########.fr       */
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

int	key(int keycode, t_win *win)
{
	if (keycode == W_KEY)
		printf("W\n");
	else if (keycode == A_KEY)
		printf("A\n");
	else if (keycode == S_KEY)
		printf("S\n");
	else if (keycode == D_KEY)
		printf("D\n");
	else if (keycode == ESC_KEY)
		end(win);
	else
		printf("|%i|\n", keycode);
	return (0);
}

int	ft_run_game(t_map *map)
{
	t_win	win;

	win.map = map;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 500, 500, "Name");
	mlx_key_hook(win.win, key, &win);
	mlx_mouse_hook(win.win, key, &win);
	mlx_loop(win.mlx);
	return (0);
}

//  mlx_destroy_window(win->mlx, win->win);
// 	mlx_destroy_display(win->mlx);
// 	free(win->mlx);