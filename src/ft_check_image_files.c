/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_image_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:31:59 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/06 15:14:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks wether each file is openable
// Add 
// ft_printf("Could not open %s\n", file);
// before the return (1) statemenet for more info which file
static int	ft_check_file(const char *file)
{
	int	fd;

	fd = ft_cooler_open((char *)file, 1);
	if (fd < 0)
	{
		return (1);
	}
	close (fd);
	return (0);
}

// Checks, wether all neccesary files can be opened
// returns 1 if no
// returns 0 if yes
int	ft_check_image_files(void)
{
	int	sum;

	sum = 0;
	sum += ft_check_file(WALL_TEXTURE);
	sum += ft_check_file(FLOOR_TEXTUE);
	sum += ft_check_file(PLAYER_TEXTURE);
	sum += ft_check_file(COIN_TEXTURE);
	sum += ft_check_file(EXIT_TEXTURE);
	if (sum > 0)
		return (ft_err_msg("Couldnt open all textures", 2));
	return (0);
}
