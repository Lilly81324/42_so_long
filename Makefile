# Remember, the .c and .o files have to be in root and not folders for this project!
# So we will need to change that at the end
# Add CFLAGS later

PROGRAM = so_long
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft

CC = cc
C_FLAGS = -Wall -Wextra -Werror

SOURCE_FILES = $(SRC_DIR)/aa_main.c \
				$(SRC_DIR)/ft_check_argc.c \
				$(SRC_DIR)/ft_check_map.c \
				$(SRC_DIR)/ft_cooler_open.c \
				$(SRC_DIR)/ft_check_first_line.c \
				$(SRC_DIR)/ft_get_map_height.c \
				$(SRC_DIR)/ft_get_map_cont.c \
				$(SRC_DIR)/ft_free_caa.c \
				$(SRC_DIR)/ft_get_map_width.c \
				$(SRC_DIR)/ft_get_map_last_width.c \
				$(SRC_DIR)/ft_check_map_count.c \
				$(SRC_DIR)/ft_check_valid_chars.c \
				$(SRC_DIR)/ft_set_map_c.c \
				$(SRC_DIR)/ft_check_map_edges.c
OBJ_FILES = $(subst $(SRC_DIR),$(OBJ_DIR),$(SOURCE_FILES:%.c=%.o))

all: $(LIBFT_LIB) $(PROGRAM)

$(PROGRAM): $(OBJ_FILES) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_LIB) -o $(PROGRAM)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir obj

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_FILES)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf obj
	rm -f $(PROGRAM)

unsinn:
	echo $(SOURCE_FILES)
	echo $(OBJ_FILES)

re: fclean all

.PHONY: all clean fclean re