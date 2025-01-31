/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:13:04 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/31 15:12:55 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

// Displayed every succedsfull move
static void	ft_display_message(t_win *win)
{
	int	got;
	int	tot;

	got = win->map->c_got;
	tot = win->map->c_tot;
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_printf("Current Mission:\n");
	if (got < tot)
		ft_printf("Collect all the Endo while staying undetected\n\n");
	else
		ft_printf("Get to the exit and escape with the loot\n\n");
	ft_printf(" ________________________\n");
	ft_printf("/                        \\\n");
	ft_printf("|  Moves: %i\n", win->map->moves);
	ft_printf("|------------------------|\n");
	ft_printf("|  %i / %i Endo collected\n", got, tot);
	if (got >= tot)
		ft_printf("\\__EXTRACTION_IS_READY___/\n");
	else
		ft_printf("\\________________________/\n");
}

// moves player into direction and returns 0 if possible
// returns 1 if invalid move or not possible
// KEY: dir = change in coords:
// W: 	-10 = -y, 				S: +10 = +y
// A: 	-01 = -x, 				D: +01 = +x
int	ft_move(t_win *win, int dir)
{
	int	x;
	int	y;

	x = win->map->p_x + (dir % 10);
	y = win->map->p_y + (dir / 10);
	if (win->map->cont[y][x] == '1')
		return (1);
	else if (win->map->cont[y][x] == 'E' && win->map->c_got != win->map->c_tot)
		return (1);
	else if (win->map->cont[y][x] == 'C')
		win->map->c_got++;
	win->map->moves++;
	ft_display_message(win);
	if (win->map->cont[y][x] == 'E')
		ft_end_win(win);
	ft_move_player(win, x, y);
	return (0);
}
