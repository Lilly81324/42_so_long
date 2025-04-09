/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:34:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/09 14:48:58 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// called when player exits programm through movements
// so not when intentionally closed, but only when exit reached
void	ft_end_win(t_win *win)
{
	ft_printf("\n-----Mission Results------\n\n");
	ft_printf("Well done Tenno. You reached the exit in %i moves\n"\
, win->map->moves);
	ft_printf("You managed to bring back all %i Endo\n", win->map->c_tot);
	if (win->map->e_got > 0)
		ft_printf("As well as defeating %i/%i Grineer\n", win->map->e_got, \
win->map->e_tot);
	if (win->map->e_tot > 0 && win->map->e_got == 0)
		ft_printf("\nPACIFISM Achievement unlocked\n");
	else if (win->map->e_tot > 0 && win->map->e_got == win->map->e_tot)
		ft_printf("\nGENOCIDE Achievement unlocked\n");
	ft_printf("\n-----------------------------\n");
	ft_end(win);
}
