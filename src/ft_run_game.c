/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:21:20 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/27 18:53:42 by sikunne          ###   ########.fr       */
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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	ft_display(t_win *win)
{
	void	*img;
	void	*img2;
	int		*height;
	int		*width;
	int		h;
	int		w;

	h = 50;
	w = 50;
	height = &h;
	width = &w;
	img = mlx_xpm_file_to_image(win->mlx, "wall.xpm", width, height);
	mlx_put_image_to_window(win->mlx, win->win, img, 0, 0);
	img2 = mlx_xpm_file_to_image(win->mlx, "wall.xpm", width, height);
	mlx_put_image_to_window(win->mlx, win->win, img2, 64, 0);
	mlx_destroy_image(win->mlx, img);
	mlx_destroy_image(win->mlx, img2);
}

int	ft_run_game(t_map *map)
{
	t_win	win;

	win.map = map;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, map->width * 64, map->height * 64, "Name");
	ft_make_img_map(&win);
	mlx_key_hook(win.win, key, &win);
	mlx_mouse_hook(win.win, key, &win);
	mlx_loop(win.mlx);
	return (0);
}

//  mlx_destroy_window(win->mlx, win->win);
// 	mlx_destroy_display(win->mlx);
// 	free(win->mlx);