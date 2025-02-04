/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:09 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/04 16:24:17 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

# define COUNTER_COLOR 111111
# define COUNTER_WIDTH 16
# define COUNTER_HEIGHT 32
# define COUNTER_WIDE_DEPTH 4
# define COUNTER_HIGH_DEPTH 4

int		ft_check_map_bonus(t_map *map);
int		ft_check_map_count_bonus(t_map *map);
int		ft_run_game_bonus(t_map *map);
int		ft_move_bonus(t_win *win, int dir);
int		ft_enemy_bonus(t_win *win);
void	ft_enemy_bounce_bonus(t_win *win, int x, int y, char type);
void	ft_enemy_recharge_bonus(t_win *win);
int		ft_enemy_decis_bonus(t_win *win, int posx, int posy, char type);
void	ft_enemy_move_bonus(t_win *win, int fx, int fy, char type);
void	ft_end_kill_bonus(t_win *win);
void	ft_draw_number(t_win *win);

#endif