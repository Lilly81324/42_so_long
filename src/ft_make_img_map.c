/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_img_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:32:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/27 19:06:23 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char *ft_cont_to_name(char in)
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

void	ft_assign_img(t_win *win, int i, int j)
{
	void	*img;
	img = mlx_xpm_file_to_image(win->mlx, ft_cont_to_name(win->map->\
	cont[j][i]), SPRITE_SIZE, SPRITE_SIZE);
	mlx_put_image_to_window(win->mlx, win->win, img, (j - 1) * SPRITE_SIZE , (i - 1) * SPRITE_SIZE);
	win->map->img[j][i] = img;
}

void	ft_make_img_map(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	printf("\n");
	printf("%i height\n", win->map->height);
	printf("%i width\n", win->map->width);
	win->map->img = (void ***)malloc(win->map->width * sizeof (void **));
	while (++i < win->map->width)
	{
		j = -1;
		win->map->img[i] = (void **)malloc(win->map->height * sizeof(void *));
		while (++j < win->map->height)
			ft_assign_img(win, i, j);
		printf("\n");
	}
	sleep(4);
	i = -1;
	j = -1;
	while (++i < win->map->width)
	{
		j = -1;
		while (++j < win->map->height)
			mlx_destroy_image(win->mlx, win->map->img[j][i]);
		free(win->map->img[i]);
	}
	free(win->map->img);
	printf("Over\n");
}

// problem here
