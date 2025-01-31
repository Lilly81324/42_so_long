/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:34:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/31 14:38:38 by sikunne          ###   ########.fr       */
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
	ft_printf("You managed to bring back all %i Endo\n\n", win->map->c_tot);
	ft_printf("-----------------------------\n");
	ft_end(win);
}
