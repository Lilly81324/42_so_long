/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_message_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:00:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/04 18:00:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Displayed every successfull move
void	ft_display_message_bonus(t_win *win)
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
