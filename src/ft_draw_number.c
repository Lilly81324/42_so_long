/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:20:51 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/04 16:53:50 by sikunne          ###   ########.fr       */
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

static void	ft_draw_zero(t_win *win, int x, int y)
{
	ft_printf("Drawing 0\n");
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
	// 0 -> 15 | 31 -> 28
	while (++i < 4)
		ft_draw_hor_line(win, x, y + height - i - 1, width);
	i = -1;
	// 0 -> 3 | 0 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x + i, y, height);
	i = -1;
	// 15 -> 13 | 0 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x + width -i -1, y, height);
}

static void	ft_draw_one(t_win *win, int x, int y)
{
	ft_printf("Drawing 1\n");
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH/2;
	i = -1;
	// 8 -> 15 | 0 -> 3
	while (++i < 4)
		ft_draw_hor_line(win, x + width, y + i, width);
	i = -1;
	// 15 -> 12 | 0 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x + (width * 2) -i -1, y, height);
}

static void	ft_draw_two(t_win *win, int x, int y)
{
	ft_printf("Drawing 2\n");
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

static void	ft_draw_three(t_win *win, int x, int y)
{
	ft_printf("Drawing 3\n");
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
	// 0 -> 15 | 14 -> 17
	while (++i < 4)
		ft_draw_hor_line(win, x, y + (height / 2) -2 + i, width);
	i = -1;
	// 0 -> 15 | 31 -> 28
	while (++i < 4)
		ft_draw_hor_line(win, x, y + height - i - 1, width);
	i = -1;
	// 15 -> 12 | 0 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x +16 -i -1, y, height);
}

static void	ft_draw_four(t_win *win, int x, int y)
{
	ft_printf("Drawing 4\n");
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH;
	i = -1;
	// 0 -> 15 | 14 -> 17
	while (++i < 4)
		ft_draw_hor_line(win, x, y + (height / 2) -2 + i, width);
	i = -1;
	// 15 -> 12 | 0 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x +16 -i -1, y, height);
	i = -1;
	// 0 -> 3 | 0 -> 15
	while (++i < 4)
		ft_draw_ver_line(win, x +i, y, height / 2);
}

static void	ft_draw_five(t_win *win, int x, int y)
{
	ft_printf("Drawing 5\n");
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
	// 0 -> 15 | 14 -> 17
	while (++i < 4)
		ft_draw_hor_line(win, x, y + (height / 2) -2 + i, width);
	i = -1;
	// 0 -> 15 | 31 -> 28
	while (++i < 4)
		ft_draw_hor_line(win, x, y + height - i - 1, width);
	i = -1;
	// 0 -> 3 | 0 -> 15
	while (++i < 4)
		ft_draw_ver_line(win, x +i, y, height / 2);
	i = -1;
	// 15 -> 12 | 16 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x +15 -i, y + 16, height / 2);
}

static void	ft_draw_six(t_win *win, int x, int y)
{
	ft_printf("Drawing 6\n");
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
	// 0 -> 15 | 14 -> 17
	while (++i < 4)
		ft_draw_hor_line(win, x, y + (height / 2) -2 + i, width);
	i = -1;
	// 0 -> 15 | 31 -> 28
	while (++i < 4)
		ft_draw_hor_line(win, x, y + height - i - 1, width);
	i = -1;
	// 0 -> 3 | 0 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x +i, y, height);
	i = -1;
	// 15 -> 12 | 16 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x +15 -i, y + 16, height / 2);
}

static void	ft_draw_seven(t_win *win, int x, int y)
{
	ft_printf("Drawing 7\n");
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH;
	i = -1;
	// 0 -> 15 | 0 -> 3
	while (++i < 4)
		ft_draw_hor_line(win, x , y + i, width);
	i = -1;
	// 8 -> 15 | 14 -> 17
	while (++i < 4)
		ft_draw_hor_line(win, x + (width / 2), y + (height / 2) -2 + i, (width / 2));
	i = -1;
	// 15 -> 12 | 0 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x +16 -i -1, y, height);
}

static void	ft_draw_eight(t_win *win, int x, int y)
{
	ft_printf("Drawing 8\n");
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
	// 0 -> 15 | 14 -> 17
	while (++i < 4)
		ft_draw_hor_line(win, x, y + (height / 2) -2 + i, width);
	i = -1;
	// 0 -> 15 | 31 -> 28
	while (++i < 4)
		ft_draw_hor_line(win, x, y + height - i - 1, width);
	i = -1;
	// 0 -> 3 | 0 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x + i, y, height);
	i = -1;
	// 15 -> 12 | 0 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x + width -i -1, y, height);
}

static void	ft_draw_nine(t_win *win, int x, int y)
{
	ft_printf("Drawing 9\n");
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
	// 0 -> 15 | 14 -> 17
	while (++i < 4)
		ft_draw_hor_line(win, x, y + (height / 2) -2 + i, width);
	i = -1;
	// 0 -> 15 | 31 -> 28
	while (++i < 4)
		ft_draw_hor_line(win, x, y + height - i - 1, width);
	i = -1;
	// 0 -> 3 | 0 -> 15
	while (++i < 4)
		ft_draw_ver_line(win, x +i, y, height / 2);
	i = -1;
	// 15 -> 12 | 0 -> 31
	while (++i < 4)
		ft_draw_ver_line(win, x + width -i -1, y, height);
}

static int	ft_get_digits(int num)
{
	int len;

	len = 1;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	ft_printf ("%i Stellen in %i\n", len, num);
	return (len);
}

void	ft_reset_count(t_win *win)
{
	int	i;

	i = -1;
	while (++i < win->map->width)
		mlx_put_image_to_window(win->mlx, win->win, win->img->wall, \
		i * SPRITE_SIZE, 0);
}

//recursively decide which number to draw where
static void	ft_num_to_draw(t_win *win, int num)
{
	int	x;
	int	y;

	if (num >= 10)
		ft_num_to_draw(win, num/10);
	x = win->map->width * SPRITE_SIZE;
	y = 8;
	x -= ft_get_digits(num) * SPRITE_SIZE;
	printf("%i at %i %i\n", num % 10, x, y);
	if (num == 0)
		ft_draw_zero(win, x, y);
	else if (num == 1)
		ft_draw_one(win, x, y);
	else if (num == 2)
		ft_draw_two(win, x, y);
	else if (num == 3)
		ft_draw_three(win, x, y);
	else if (num == 4)
		ft_draw_four(win, x, y);
	else if (num == 5)
		ft_draw_five(win, x, y);
	else if (num == 6)
		ft_draw_six(win, x, y);
	else if (num == 7)
		ft_draw_seven(win, x, y);
	else if (num == 8)
		ft_draw_eight(win, x, y);
	else if (num == 9)
		ft_draw_nine(win, x, y);
}

void	ft_draw_number(t_win *win)
{
	ft_reset_count(win);
	ft_num_to_draw(win, win->map->moves);
}
