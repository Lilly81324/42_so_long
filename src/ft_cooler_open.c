/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cooler_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:11:23 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 17:54:04 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// translates files that have no ./ in front but should, into ./file
// three cases:
// works for absoulte paths like /home/sikunne/file.exe
// and also for relative paths file.exe, ./file.exe, dir/file.exe
// allocates and frees itself
// returns the opened fd, which needs to be closed later
int	ft_cooler_open(char *filename)
{
	int		i;
	char	*copy;
	int		fd;

	i = -1;
	if (filename[0] == '/' || (filename[0] == '.' && filename[1] == '/'))
		fd = open(filename, O_RDWR);
	else
	{
		copy = (char *)malloc((ft_strlen(filename) + 3) * sizeof(char));
		copy[0] = '.';
		copy[1] = '/';
		while (filename[++i] != '\0')
			copy[i + 2] = filename[i];
		copy[i + 2] = '\0';
		fd = open(copy, O_RDWR);
		free(copy);
	}
	if (fd > 0)
		return (fd);
	errno = 2;
	perror("Could not open file");
	return (-1);
}
