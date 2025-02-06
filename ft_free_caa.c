/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_caa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:09:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/06 12:35:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Frees 2d Array of chars
// Returns <ret>
// Used to free the map->contents
int	ft_free_caa(char **arr, int ret)
{
	int	i;

	i = -1;
	if (arr == NULL)
		return (ret);
	while (arr[++i] != NULL)
		free(arr[i]);
	free(arr);
	return (ret);
}
