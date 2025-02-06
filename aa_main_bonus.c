/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:47:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/03 15:51:59 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// returns -1 if argc is wrong
static int	ft_check_argc(int argc)
{
	if (argc < 2)
		return (ft_err_msg("No map specified", 5));
	if (argc > 2)
		return (ft_err_msg("Too many arguments given", 7));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (ft_check_argc(argc) != 0)
		return (errno);
	map.e_got = 0;
	map.cont = NULL;
	map.name = argv[1];
	if (ft_check_map_bonus(&map) != 0)
	{
		ft_free_caa(map.cont, 1);
		return (errno);
	}
	if (ft_run_game_bonus(&map) != 0)
		return (ft_free_caa(map.cont, errno));
	return (ft_free_caa(map.cont, 0));
}

// issues when quitting right at start