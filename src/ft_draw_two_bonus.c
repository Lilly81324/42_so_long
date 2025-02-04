/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_two_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:08:09 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/04 18:09:25 by sikunne          ###   ########.fr       */
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

// Draws a '2' at <x> <y> in the window
void	ft_draw_two_bonus(t_win *win, int x, int y)
{
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH;
	i = -1;
	// 0 -> 15 | 0 -> 3
	while (++i < 4)
		ft_draw_hor_line(win, x, y + i, width);
	i = -1;
	// 15 -> 12 | 0 -> 15
	while (++i < 4)
		ft_draw_ver_line(win, x +15 -i, y, height / 2);
	i = -1;
	// 0 -> 15 | 14 -> 17
	while (++i < 4)
		ft_draw_hor_line(win, x, y + (height / 2) -2 + i, width);
	i = -1;
	// 0 -> 3 | 16 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x +i, y + 16, height / 2);
	i = -1;
	// 0 -> 15 | 31 -> 28
	while (++i < 4)
		ft_draw_hor_line(win, x, y + height - i - 1, width);
}
