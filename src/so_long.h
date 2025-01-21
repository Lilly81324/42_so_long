/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:19:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/21 18:46:31 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	int		fd;
	int		lines;
	int		width;
	int		height;
	char	**cont;
}	t_map;

int	ft_check_argc(int argc);
int	ft_check_map(char *map);
int	ft_cooler_open(char *filename);
int	ft_get_height(t_map *map);
int	ft_get_width(t_map *map);

#endif