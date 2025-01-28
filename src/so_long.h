/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:19:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/28 14:00:28 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define SPRITE_SIZE 64

typedef struct s_map
{
	char	*name;
	int		height;
	char	**cont;
	int		width;
	int		p_x;
	int		p_y;
	int		c_tot;
	int		c_got;
}	t_map;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	***img;
	t_map	*map;
}	t_win;

// Used to count how many of each character are in the map
// Called somewhere in ft_check_map
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
char	**ft_copy_caa(char **orig);
void	ft_print_caa(char **map);
int		ft_run_game(t_map *map);
void	ft_make_img_map(t_win *win);

#endif