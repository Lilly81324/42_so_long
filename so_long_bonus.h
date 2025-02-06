/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:28:09 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/06 14:40:00 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

// For changing the look of the counter, all values in pixels
// Colour from HEX to Decimal code converted
# define COUNTER_COLOR 10075334
// Width of each number in the counter
# define COUNTER_WIDTH 21
// Height of each number in the counter
# define COUNTER_HEIGHT 48
// How far form the top the counter begins,
# define COUNTER_Y_OFFSET 8
// How far form the right side the counter begins,
# define COUNTER_X_OFFSET 8
// Spacing between each character
# define COUNTER_SPACING 10
// How wide each vertical line in the counter is
# define COUNTER_WIDE_DEPTH 6
// How high each horizontal line in the counter is
# define COUNTER_HIGH_DEPTH 3

// Adjusted base functions for bonus
int		ft_check_map_bonus(t_map *map);
int		ft_check_map_count_bonus(t_map *map);
int		ft_check_image_files_bonus(void);
int		ft_run_game_bonus(t_map *map);
void	ft_make_images_bonus(t_win *win);
int		ft_move_bonus(t_win *win, int dir);

// Enemy behaviour
int		ft_enemy_bonus(t_win *win);
int		ft_enemy_decis_bonus(t_win *win, int posx, int posy, char type);
void	ft_enemy_bounce_bonus(t_win *win, int x, int y, char type);
void	ft_enemy_recharge_bonus(t_win *win);
void	ft_enemy_move_bonus(t_win *win, int fx, int fy, char type);
void	ft_end_kill_bonus(t_win *win);

// For drawing the counter
void	ft_draw_counter_bonus(t_win *win);
void	ft_draw_zero_bonus(t_win *win, int x, int y);
void	ft_draw_one_bonus(t_win *win, int x, int y);
void	ft_draw_two_bonus(t_win *win, int x, int y);
void	ft_draw_three_bonus(t_win *win, int x, int y);
void	ft_draw_four_bonus(t_win *win, int x, int y);
void	ft_draw_five_bonus(t_win *win, int x, int y);
void	ft_draw_six_bonus(t_win *win, int x, int y);
void	ft_draw_seven_bonus(t_win *win, int x, int y);
void	ft_draw_eight_bonus(t_win *win, int x, int y);
void	ft_draw_nine_bonus(t_win *win, int x, int y);

#endif