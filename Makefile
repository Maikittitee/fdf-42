NAME	:= fdf

CC	:= gcc
CFLAGS	:= -Wall -Wextra -Werror

LIB_DIR	:= ./lib

SRCS	:=	fdf.c \
			fdf_utils.c \
			fdf_map_data.c \
			fdf_draw.c \
			fdf_assign.c \
			fdf_rotate.c \
			fdf_initial.c \
			fdf_key.c \
			fdf_err.c \
			fdf_check_read.c

OBJS	:= $(SRCS:.c=.o)

LIBFT_DIR	:= $(LIB_DIR)/libft
LIBFT	:= $(LIBFT_DIR)/libft.a

MLX_DIR	:= ./mlx
MINILIBX	:= $(MLX_DIR)/libmlx.a

FRAME_W	:= -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) -I$(LIBFT_DIR)\
		-L$(LIBFT_DIR) -Lmlx -lft -lmlx $(FRAME_W) -o $(NAME)

$(MINILIBX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean: 
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re