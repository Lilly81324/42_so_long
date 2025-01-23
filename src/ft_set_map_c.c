/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:14:40 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/23 13:14:40 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_set_map_c(t_map_cnt *map)
{
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->zero = 0;
	map->one = 0;
	map->other = 0;
}
