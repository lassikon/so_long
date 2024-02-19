NAME		:= so_long
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
LIBMLX		:= MLX42
LIBFT_DIR	:= libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
# MLX42	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX42	:= $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L"/Users/lkonttin/.brew/opt/glfw/lib/"
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
			animate_player.c
			
OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(MLX42) $(HEADERS) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft