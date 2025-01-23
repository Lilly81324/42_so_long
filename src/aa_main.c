/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:47:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/23 18:47:12 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map.cont = NULL;
	map.name = argv[1];
	if (ft_check_map(&map) != 0)
	{
		ft_free_caa(map.cont, 1);
		return (errno);
	}
	ft_printf("Continuing with valid map\n");
	ft_print_caa(map.cont);
	return (ft_free_caa(map.cont, 0));
}

// Things can be in the map file after the map and one \n
// Might not be intended behaviour