/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_image_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:31:59 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/30 17:06:21 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_file(const char *file)
{
	int	fd;

	fd = ft_cooler_open(file, 1);
	if (fd < 0)
	{
		close (fd);
		ft_printf("Could not open %s\n", file);
		return (1);
	}
	close (fd);
	return (0);
}

int	ft_check_image_files(void)
{
	int sum;

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
