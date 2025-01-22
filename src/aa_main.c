/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:47:18 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 17:58:52 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO 
// Fix get_width seeing a file that ends exaclty at the last character of map as invalid
// Its because that last line is mssing a \n which is why it counts as such

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
	return (ft_free_caa(map.cont, 0));
}
