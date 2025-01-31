/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cont_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:51:30 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/31 14:51:30 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// turns each character from the map object
// into the respective image from the image object
void	*ft_cont_to_img(t_win *win, char in)
{
	if (in == '1')
		return (win->img->wall);
	else if (in == '0')
		return (win->img->empty);
	else if (in == 'C')
		return (win->img->coin);
	else if (in == 'P')
		return (win->img->player);
	else if (in == 'E')
		return (win->img->exit);
	return (win->img->player);
}
