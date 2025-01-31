# Remember, the .c and .o files have to be in root and not folders for this project!
# So we will need to change that at the end
# Add CFLAGS later

PROGRAM = so_long
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

CC = cc
C_FLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -Lmlx_linux -Imlx_linux -lX11 -lXext -lm -lz -Ofast

SOURCE_FILES = $(addprefix $(SRC_DIR), aa_main.c \
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
OBJ_FILES = $(subst $(SRC_DIR),$(OBJ_DIR),$(SOURCE_FILES:%.c=%.o))

all: $(MLX_LIB) $(PROGRAM)

$(PROGRAM): $(OBJ_FILES) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(MLX_LIB) $(MLX_FLAGS) $(LIBFT_LIB) -o $(PROGRAM)

$(MLX_LIB): minilibx-linux
	@make -C $(MLX_DIR)

minilibx-linux:
	git clone https://github.com/42Paris/minilibx-linux.git $@

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir obj

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	-make -sC $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(MLX_DIR)
	make -C $(LIBFT_DIR) fclean
	rm -rf obj
	rm -f $(PROGRAM)

show:
	echo $(SOURCE_FILES)
	echo $(OBJ_FILES)

re: fclean all

.PHONY: all clean fclean re