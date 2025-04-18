/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:32:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/30 15:43:20 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// draws the map by putting images in each position
// limits are map height and map width
void	ft_display_map(t_win *win)
{
	int		i;
	int		j;
	void	*img;
	int		si;

	i = -1;
	si = SPRITE_SIZE;
	while (++i < win->map->height)
	{
		j = -1;
		while (++j < win->map->width)
		{
			img = ft_cont_to_img(win, win->map->cont[i][j]);
			mlx_put_image_to_window(win->mlx, win->win, img, j * si, i * si);
		}
	}
	i = -1;
}
