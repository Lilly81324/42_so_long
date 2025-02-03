/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cont_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:51:30 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/03 15:09:42 by sikunne          ###   ########.fr       */
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
	else if (in == 'U' || in == 'u')
		return (win->img->up);
	else if (in == 'R' || in == 'r')
		return (win->img->right);
	else if (in == 'D' || in == 'd')
		return (win->img->down);
	else if (in == 'L' || in == 'l')
		return (win->img->left);
	return (win->img->player);
}
