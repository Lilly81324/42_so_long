/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:46:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/30 16:27:55 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checks wether the <len> characters in <comp> are the
// last <len> characters in <src>
// returns 0 if yes
// returns 1 if no
// Example: ft_ends_in(".exe", 4, src) -> returns 0 for alle .exe files
// Assumes that src and comp are both equal to or longer then <len>
static int	ft_ends_in(const char *comp, int len, char *src)
{
	int	start;

	start = 0;
	while (src[start] != '\0')
		start++;
	start = start - len;
	while (len >= 0)
	{
		if (comp[len] != src[start + len])
			return (1);
		len--;
	}
	return (0);
}

int	ft_check_map_name(t_map *map)
{
	int	i;

	if (map->name == NULL)
		return (ft_err_msg("ERROR Map name is null", 2));
	if (map->name[0] == '\0')
		return (ft_err_msg("ERROR Map name is empty", 2));
	i = 0;
	while (map->name[i] != '\0')
		i++;
	if (i < 5)
		return (ft_err_msg("ERROR Map name too short to end in .ber", 5));
	if (ft_ends_in(".ber", 4, map->name) == 1)
		return (ft_err_msg("ERROR File does not end in '.ber'", 5));
	return (0);
}
