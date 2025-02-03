/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_kill_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:39:33 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/03 18:26:30 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end_kill_bonus(t_win *win)
{
	int	x;
	int	y;

	x = win->map->p_x;
	y = win->map->p_y;
	ft_printf("\n-----Mission Results------\n\n");
	ft_printf("You were caught and defeated, Tenno.\n");
	ft_printf("Next time be more carefull around [%i|%i].\n\n", x, y);
	ft_printf("-----------------------------\n");
	ft_end(win);
	return ;
}
