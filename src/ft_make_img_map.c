/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_img_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:32:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/28 00:03:17 by sikunne          ###   ########.fr       */
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
		return ("apple.xpm");
	else if (in == 'E')
		return ("apple.xpm");
	return ("apple.xpm");
}

// the column is j
// the row is i
void	ft_assign_img(t_win *win, int i, int j)
{
	void	*img;
	int		size;

	size = SPRITE_SIZE;
	img = mlx_xpm_file_to_image(win->mlx, ft_cont_to_name(win->map->\
	cont[i][j]), &size, &size);
	mlx_put_image_to_window(win->mlx, win->win, img, j * size, i * size);
	win->map->img[i][j] = img;
}

// the column is j - x
// the row is i - y
// i j
void	ft_make_img_map(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	win->map->img = (void ***)malloc(win->map->height * sizeof (void **));
	while (++i < win->map->height)
	{
		j = -1;
		win->map->img[i] = (void **)malloc(win->map->width * sizeof (void *));
		while (++j < win->map->height)
			ft_assign_img(win, i, j);
	}
	i = -1;
	while (++i < win->map->height)
	{
		j = -1;
		while (++j < win->map->width)
			mlx_destroy_image(win->mlx, win->map->img[i][j]);
		free(win->map->img[i]);
	}
	free(win->map->img);
	printf("Over\n");
}

// problem here
