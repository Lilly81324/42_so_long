# Remember, the .c and .o files have to be in root and not folders for this project!
# So we will need to change that at the end

PROGRAM = so_long
BASE = .base
BONUS = .bonus
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a

# Directories
SRC_DIR = ./
OBJ_DIR = ./obj/
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

# For compiling
CC = cc
C_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I/usr/include -Iminilibx-linux

# Files to compile
SOURCE_FILES = $(addprefix $(SRC_DIR), \
				ft_check_map.c \
				ft_check_map_name.c \
				ft_cooler_open.c \
				ft_free_caa.c \
				ft_get_map_width.c \
				ft_check_map_count.c \
				ft_err_msg.c \
				ft_check_map_path.c \
				ft_copy_caa.c \
				ft_run_game.c \
				ft_check_image_files.c \
  				ft_cont_to_img.c \
				ft_display_map.c \
				ft_move.c \
				ft_end_quit.c \
				ft_end_win.c \
				ft_end.c \
				ft_make_images.c)
MAIN_SRC =  $(SRC_DIR)aa_main.c
MAIN_OBJ = $(OBJ_DIR)aa_main.o
BNS_SRC_FILES =  $(addprefix $(SRC_DIR), \
				aa_main_bonus.c \
				ft_check_map_bonus.c \
				ft_check_map_count_bonus.c \
				ft_run_game_bonus.c \
				ft_display_message_bonus.c \
				ft_move_bonus.c \
				ft_enemy_bonus.c \
				ft_enemy_bounce_bonus.c \
				ft_enemy_recharge_bonus.c \
				ft_enemy_decis_bonus.c \
				ft_enemy_move_bonus.c \
				ft_end_kill_bonus.c \
				ft_draw_counter_bonus.c \
				ft_draw_zero_bonus.c \
				ft_draw_one_bonus.c \
				ft_draw_two_bonus.c \
				ft_draw_three_bonus.c \
				ft_draw_four_bonus.c \
				ft_draw_five_bonus.c \
				ft_draw_six_bonus.c \
				ft_draw_seven_bonus.c \
				ft_draw_eight_bonus.c \
				ft_draw_nine_bonus.c)
OBJ_FILES = $(subst $(SRC_DIR),$(OBJ_DIR),$(SOURCE_FILES:%.c=%.o))
BNS_OBJ_FILES = $(subst $(SRC_DIR),$(OBJ_DIR),$(BNS_SRC_FILES:%.c=%.o))

##############################################################################

all: $(BASE)

$(BASE): $(LIBFT_LIB) $(OBJ_FILES) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(MAIN_OBJ) $(MLX_FLAGS) $(LIBFT_LIB) -o $(PROGRAM)
	rm -rf .bonus
	touch $(BASE)

bonus: $(BONUS)

$(BONUS): $(LIBFT_LIB) $(OBJ_FILES) $(BNS_OBJ_FILES)
	$(CC) $(CFLAGS) $(BNS_OBJ_FILES) $(OBJ_FILES) $(MLX_FLAGS) $(LIBFT_LIB) -o $(PROGRAM)
	rm -rf .base
	touch $(BONUS)

$(LIBFT_DIR):
	git clone git@github.com:Lilly81324/42_libft.git $@

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $@

$(OBJ_DIR):
	mkdir obj

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(MLX_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_LIB): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

clean:
	-make -sC $(MLX_DIR) clean
	-make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(MLX_DIR)
	-make -C $(LIBFT_DIR) fclean
	rm -rf $(BASE)
	rm -rf $(BONUS)
	rm -f $(PROGRAM)

lib: $(LIBFT_DIR)

show:
	echo $(SOURCE_FILES)
	echo $(OBJ_FILES)

run:
	valgrind --leak-check=full ./$(PROGRAM) maps/enemy.ber

re: fclean all

.PHONY: all bonus clean fclean show run re