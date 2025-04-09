/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_counter_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:20:51 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/09 14:45:20 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Returns how many digits a positive number has
static int	ft_get_digits(int num)
{
	int	len;

	len = 1;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

// Runs the function for drawing the number, based off that <num>
static void	ft_translate_number(t_win *win, int num, int x, int y)
{
	if (num % 10 == 0)
		ft_draw_zero_bonus(win, x, y);
	else if (num % 10 == 1)
		ft_draw_one_bonus(win, x, y);
	else if (num % 10 == 2)
		ft_draw_two_bonus(win, x, y);
	else if (num % 10 == 3)
		ft_draw_three_bonus(win, x, y);
	else if (num % 10 == 4)
		ft_draw_four_bonus(win, x, y);
	else if (num % 10 == 5)
		ft_draw_five_bonus(win, x, y);
	else if (num % 10 == 6)
		ft_draw_six_bonus(win, x, y);
	else if (num % 10 == 7)
		ft_draw_seven_bonus(win, x, y);
	else if (num % 10 == 8)
		ft_draw_eight_bonus(win, x, y);
	else if (num % 10 == 9)
		ft_draw_nine_bonus(win, x, y);
}

// recursively decide which number to draw and where
static void	ft_num_to_draw(t_win *win, int num, int len)
{
	int	x;
	int	y;

	if (num >= 10)
		ft_num_to_draw(win, num / 10, len);
	x = win->map->width * SPRITE_SIZE;
	y = COUNTER_Y_OFFSET;
	x -= COUNTER_X_OFFSET + COUNTER_WIDTH;
	x -= (COUNTER_SPACING + COUNTER_WIDTH) * (len - ft_get_digits(num));
	ft_translate_number(win, num, x, y);
}

// Draws the first line again, so the pixels of the old counter get
// removed and then draws the number of moves recursively 
void	ft_draw_counter_bonus(t_win *win)
{
	int	i;

	i = -1;
	while (++i < win->map->width)
		mlx_put_image_to_window(win->mlx, win->win, win->img->wall, \
i * SPRITE_SIZE, 0);
	ft_num_to_draw(win, win->map->moves, ft_get_digits(win->map->moves));
}
