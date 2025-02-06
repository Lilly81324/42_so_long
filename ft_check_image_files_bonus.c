/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_image_files_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:24:03 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/06 14:24:41 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_check_file(const char *file)
{
	int	fd;

	fd = ft_cooler_open((char *)file, 1);
	if (fd < 0)
	{
		close (fd);
		ft_printf("Could not open %s\n", file);
		return (1);
	}
	close (fd);
	return (0);
}

// Checks, wether all neccesary files can be opened
// returns 1 if no
// returns 0 if yes
int	ft_check_image_files_bonus(void)
{
	int	sum;

	sum = 0;
	sum += ft_check_file(WALL_TEXTURE);
	sum += ft_check_file(FLOOR_TEXTUE);
	sum += ft_check_file(PLAYER_TEXTURE);
	sum += ft_check_file(COIN_TEXTURE);
	sum += ft_check_file(EXIT_TEXTURE);
	sum += ft_check_file(UP_TEXTURE);
	sum += ft_check_file(RIGHT_TEXTURE);
	sum += ft_check_file(DOWN_TEXTURE);
	sum += ft_check_file(LEFT_TEXTURE);
	if (sum > 0)
		return (ft_err_msg("Couldnt open all textures", 2));
	return (0);
}
