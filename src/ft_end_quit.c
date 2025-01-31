/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:54:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/31 14:35:18 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_end_quit(t_win *win)
{
	ft_printf("\n-----Mission Results------\n\n");
	ft_printf("You have aborted the mission Tenno.\n");
	ft_printf("The Grineer will get to keep their Endo for another day.\n\n");
	ft_printf("-----------------------------\n");
	ft_end(win);
	return (0);
}
