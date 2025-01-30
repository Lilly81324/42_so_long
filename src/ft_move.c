/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:13:04 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/30 18:05:26 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// moves player to x and y
// sets players old position to epmty
// then sets new position to player
// then updates player coordinates
static void	ft_move_player(t_win *win, int x, int y)
{
	win->map->cont[win->map->p_y][win->map->p_x] = '0';
	win->map->cont[y][x] = 'P';
	win->map->p_x = x;
	win->map->p_y = y;
}

// called when player exits programm through movements
// so not when intentionally closed, but only when exit reached
static void	ft_moved_to_end(t_win *win)
{
	ft_printf("\n-----Mission Results------\n\n");
	ft_printf("Well done Tenno. You reached the exit in %i moves\n"\
	, win->map->moves);
	ft_printf("You managed to bring back all %i Endo\n", win->map->c_tot);
	ft_printf("-----------------------------\n");
	ft_end(win);
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
		ft_moved_to_end(win);
	ft_move_player(win, x, y);
	ft_display_map(win);
	return (0);
}
