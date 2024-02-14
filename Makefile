NAME		:= so_long
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
LIBMLX		:= MLX42
LIBFT_DIR	:= libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
MLX42	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT	:= $(LIBFT_DIR)/libft.a
SRCS	:= $(shell find -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) -g $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) -g $(OBJS) $(MLX42) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft