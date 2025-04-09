/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_seven_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:14:00 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/09 14:45:43 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Draws <length> pixels to the right, starting from <x> <y>
static void	ft_draw_hor_line(t_win *win, int x, int y, int length)
{
	int	i;

	i = -1;
	while (++i < length)
		mlx_pixel_put(win->mlx, win->win, x + i, y, COUNTER_COLOR);
}

// Draws <length> pixels downward, starting from <x> <y>
static void	ft_draw_ver_line(t_win *win, int x, int y, int length)
{
	int	i;

	i = -1;
	while (++i < length)
		mlx_pixel_put(win->mlx, win->win, x, y + i, COUNTER_COLOR);
}

// Draws a '7' at <x> <y> in the window
void	ft_draw_seven_bonus(t_win *win, int x, int y)
{
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH;
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		ft_draw_hor_line(win, x, y + i, width);
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		ft_draw_hor_line(win, x + (width / 2), y + (height / 2) - \
(COUNTER_HIGH_DEPTH / 2) + i, (width / 2));
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		ft_draw_ver_line(win, x + width - i -1, y, height);
}
