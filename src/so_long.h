/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:19:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/30 16:57:10 by sikunne          ###   ########.fr       */
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
# define CLOSE_BUTTON -16777128
# define WALL_TEXTURE "wall.xpm"
# define FLOOR_TEXTUE "free.xpm"
# define PLAYER_TEXTURE "player1.xpm"
# define COIN_TEXTURE "coin.xpm"
# define EXIT_TEXTURE "exit.xpm"

// map object that represents play area
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
	int		moves;
}	t_map;

// Used to count how many of each character are in the map
// Called somewhere in ft_check_map
// otherwise irrelevant
typedef struct s_map_cnt
{
	int	one;
	int	p;
	int	e;
	int	c;
	int	other;
}	t_map_cnt;

// image object which holds the images of the map
typedef struct s_img
{
	void	*wall;
	void	*empty;
	void	*player;
	void	*coin;
	void	*exit;
}	t_img;

// window object which holds map, images and windows
// as well as mlx pointer
typedef struct s_win
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_map	*map;
}	t_win;

// Utilities used everywhere
int		ft_free_caa(char **arr, int ret);
int		ft_err_msg(const char *str, int err);

// Validating and setting up map obect
int		ft_check_map(t_map *map);
int		ft_check_map_name(t_map *map);
int		ft_cooler_open(char *filename, int mode);
int		ft_get_map_width(t_map *map);
int		ft_check_map_count(t_map *map);
int		ft_check_map_path(t_map *map);
char	**ft_copy_caa(char **orig);

// Actual Game
int		ft_run_game(t_map *map);
int		ft_check_image_files(void);
void	ft_make_images(t_win *win);
void	ft_display_map(t_win *win);
int		ft_move(t_win *win, int dir);
void	end(t_win *win);

#endif