/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:13:04 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/05 17:20:04 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// moves player to x and y
// sets players old position to epmty
// then sets new position to player
// then updates player coordinates
static void	ft_move_player(t_win *win, int x, int y)
{
	void	*img;
	int		si;

	si = SPRITE_SIZE;
	win->map->cont[win->map->p_y][win->map->p_x] = '0';
	img = ft_cont_to_img(win, '0');
	mlx_put_image_to_window(win->mlx, win->win, img, \
				win->map->p_x * si, win->map->p_y * si);
	win->map->cont[y][x] = 'P';
	img = ft_cont_to_img(win, 'P');
	mlx_put_image_to_window(win->mlx, win->win, img, \
				x * si, y * si);
	win->map->p_x = x;
	win->map->p_y = y;
	ft_enemy_bonus(win);
}

// moves player into direction and returns 0 if possible
// returns 1 if invalid move or not possible
// KEY: dir = change in coords:
// A: 	-10 = -x, 				D: +10 = +x
// W: 	-01 = -y, 				S: +01 = +y
int	ft_move_bonus(t_win *win, int dir)
{
	int	x;
	int	y;

	x = win->map->p_x + (dir / 10);
	y = win->map->p_y + (dir % 10);
	if (win->map->cont[y][x] == '1')
		return (1);
	else if (win->map->cont[y][x] == 'E' && win->map->c_got != win->map->c_tot)
		return (1);
	else if (win->map->cont[y][x] == 'C')
		win->map->c_got++;
	else if (ft_char_in_str("URLDurld", win->map->cont[y][x]) == 1)
		win->map->e_got++;
	win->map->moves++;
	ft_display_message_bonus(win);
	if (win->map->cont[y][x] == 'E')
		ft_end_win(win);
	if (win->map->moves >= MAX_MOVES)
		ft_end_quit(win);
	ft_draw_counter_bonus(win);
	ft_move_player(win, x, y);
	return (0);
}
