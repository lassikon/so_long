NAME		:= so_long
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
MLXFLAGS	:= -Iinclude -lglfw -L"/Users/lkonttin/.brew/opt/glfw/lib/"
MLX_DIR		:= ./MLX42
LIBFT_DIR	:= ./libft

HEADERS	:= -I ./include -I $(MLX_DIR)/include -I $(LIBFT)/include
MLX42	:= $(MLX_DIR)/build/libmlx42.a
LIBFT	:= $(LIBFT_DIR)/libft.a
SRCS	:= 	so_long.c \
			get_map.c \
			free_n_error.c \
			loop.c \
			moves.c \
			open_window.c \
			validate_map.c \
			collisions.c \
			check_path.c \
			load_textures.c \
			textures_to_images.c \
			move_images.c \
			animate_player.c \
			monster_tex_n_img.c \
			monster_movement.c \
			init_struct.c \
			
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(MLX42):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(LIBFT) $(OBJS) $(MLX42)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(MLXFLAGS) $(HEADERS) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS)
	@rm -rf $(MLX_DIR)/build

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re