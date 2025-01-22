/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:19:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 17:19:48 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_map
{
	char	*name;
	int		height;
	char	**cont;
	int		width;
}	t_map;

int		ft_check_argc(int argc);
int		ft_check_map(t_map *map);
int		ft_cooler_open(char *filename);
char	*ft_check_first_line(int fd);
void	ft_get_map_height(t_map *map, int fd, char *first_line);
int		ft_get_map_cont(t_map *map);
int		ft_free_caa(char **arr, int ret);
int		ft_get_map_width(t_map *map);

#endif