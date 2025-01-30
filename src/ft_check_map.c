/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:40:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/30 17:10:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns either the first line if valid
// if invalid, frees and closes map and buffer
// returns NULL if invalid
static char	*ft_check_first_line(int fd)
{
	char	*first_line;

	first_line = get_next_line(fd);
	if (first_line == NULL || first_line[0] == '\0' || first_line[0] == '\n')
	{
		ft_printf("Error\n");
		perror("Map File is empty or invalid");
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

// gets the amount of lines of content that are in the map
// and saves them in map.height
// closes the file, since it needs to read through
static void	ft_get_map_height(t_map *map, int fd, char *first_line)
{
	int		joever;
	char	*line;

	joever = 0;
	line = first_line;
	map->height = 0;
	while (line != NULL && line[0] != '\n')
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

// opens the map by name
// checks if openable RETURNS -1 if not
// reads map file into map object
// closes map file
static int	ft_get_map_cont(t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	fd = ft_cooler_open(map->name, 0);
	if (fd < 0)
		return (1);
	map->cont = (char **)malloc((map->height + 1) * sizeof(char *));
	while (++i < map->height)
		map->cont[i] = get_next_line(fd);
	map->cont[i] = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

// checks if the first and last line are entirely 1
// and if the first and last character of all otehr lines are 1
// if yes returns 0
// otherwise it returns 1
static int	ft_check_map_edges(t_map *map)
{
	int		i;
	char	*err;

	i = -1;
	err = "Map not properly enclosed";
	while (++i < map->width)
	{
		if (map->cont[0][i] != '1')
			return (ft_err_msg(err, 5));
	}
	i = 0;
	while (++i < map->height - 1)
	{
		if (map->cont[i][0] != '1')
			return (ft_err_msg(err, 5));
		if (map->cont[i][map->width - 1] != '1')
			return (ft_err_msg(err, 5));
	}
	i = -1;
	while (++i < map->width)
	{
		if (map->cont[map->height - 1][i] != '1')
			return (ft_err_msg(err, 5));
	}
	return (0);
}

// Open the file and check the first line
// Then continue checking the rest of the map and count the height
// Then close the map and read its contents into the map object
// Read the width of each line and check if one is longer than the rest
// Count the different characters that are in the map and check them
// Check that all the edges are 1s
// return 0 if map is okay
// otherwise return 1
int	ft_check_map(t_map *map)
{
	int		fd;
	char	*first_line;

	if (ft_check_map_name(map) != 0)
		return (1);
	fd = ft_cooler_open(map->name, 0);
	if (fd < 0)
		return (1);
	first_line = ft_check_first_line(fd);
	if (first_line == NULL)
		return (1);
	ft_get_map_height(map, fd, first_line);
	if (ft_get_map_cont(map) != 0)
		return (1);
	if (ft_get_map_width(map) != 0)
		return (1);
	if (ft_check_map_count(map) != 0)
		return (1);
	if (ft_check_map_edges(map) != 0)
		return (1);
	if (ft_check_map_path(map) != 0)
		return (1);
	return (0);
}
