/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_img_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:32:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/28 13:31:56 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_cont_to_name(char in)
{
	if (in == '1')
		return ("wall.xpm");
	else if (in == '0')
		return ("free.xpm");
	else if (in == 'C')
		return ("apple.xpm");
	else if (in == 'P')
		return ("player.xpm");
	else if (in == 'E')
		return ("exit.xpm");
	return ("apple.xpm");
}

// returns an mlx_img based off of given coordinates in map->cont
void	ft_assign_img(t_win *win, int i, int j)
{
	void	*img;
	int		size;

	size = SPRITE_SIZE;
	img = mlx_xpm_file_to_image(win->mlx, ft_cont_to_name(win->map->\
	cont[i][j]), &size, &size);
	mlx_put_image_to_window(win->mlx, win->win, img, j * size, i * size);
	win->img[i][j] = img;
}

// draws the map by allocating a 2d array in win->map->img
// based off of the map->content 2d array
// the column is j - x
// the row is i - y
// immediately frees and destroys iamges and 2d array after
void	ft_make_img_map(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	win->img = (void ***)malloc(win->map->height * sizeof (void **));
	while (++i < win->map->height)
	{
		j = -1;
		win->img[i] = (void **)malloc(win->map->width * sizeof (void *));
		while (++j < win->map->width)
			ft_assign_img(win, i, j);
	}
	i = -1;
	while (++i < win->map->height)
	{
		j = -1;
		while (++j < win->map->width)
			mlx_destroy_image(win->mlx, win->img[i][j]);
		free(win->img[i]);
	}
	free(win->img);
}
