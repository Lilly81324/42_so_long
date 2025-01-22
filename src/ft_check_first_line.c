/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_first_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:25:22 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 17:29:48 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns either the first line if valid
// if invalid, frees and closes map and buffer
// returns NULL if invalid
char	*ft_check_first_line(int fd)
{
	char	*first_line;

	first_line = get_next_line(fd);
	if (first_line == NULL || first_line[0] == '\0' || first_line[0] == '\n')
	{
		perror("ERROR Map File is empty or invalid");
		free(first_line);
		first_line = NULL;
	}
	if (first_line != NULL)
		return (first_line);
	first_line = get_next_line(fd);
	while (first_line != NULL)
	{
		free(first_line);
		first_line = get_next_line(fd);
	}
	close(fd);
	errno = 5;
	return (NULL);
}
