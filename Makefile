NAME = fractol

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = -Imlx -lmlx -framework OpenGL -framework AppKit

SRC		=		main.c \
				utils.c \
				utils2.c \
				error.c \
				burning_ship.c \
				drop.c \
				julia.c \
				lambada.c \
				mandelbrot.c \
				spider.c \
				cameramoving.c \
				graphica.c \

OB = $(SRC:.c=.o)

MLX_DIR = minilibx
SRCS_DIR = srcs

SRCS        = $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS        = $(addprefix $(SRCS_DIR)/, $(OB))

INCLUDE = -I includes

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(MLX) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
