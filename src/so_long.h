/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:19:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/23 17:00:53 by sikunne          ###   ########.fr       */
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

typedef struct s_map_cnt
{
	int	one;
	int	p;
	int	e;
	int	c;
	int	other;
}	t_map_cnt;

int		ft_check_map(t_map *map);
int		ft_cooler_open(char *filename);
int		ft_free_caa(char **arr, int ret);
int		ft_get_map_width(t_map *map);
int		ft_check_map_count(t_map *map);
int		ft_err_msg(const char *str, int err);
int		ft_check_map_path(t_map *map);

#endif