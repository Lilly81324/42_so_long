/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_caa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:12:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/06 12:47:24 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// creates and returns a copy of an array of arrays of characters
// used to prepare a copy pof map->content to flood fill
char	**ft_copy_caa(char **orig)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	while (orig[i] != NULL)
		i++;
	copy = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	while (orig[i] != NULL)
	{
		j = 0;
		while (orig[i][j] != '\0' && orig[i][j] != '\n')
			j++;
		copy[i] = ft_strdup(orig[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
