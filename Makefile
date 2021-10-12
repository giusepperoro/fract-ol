NAME = fractol

CC = gcc
CFLAGS = -Wall -O2 -I ./includes/ -I ./mlx/
FLAGS = -O2 -Lmlx -lmlx -framework OpenGL -framework AppKit

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
				graphica.c

OB = $(SRC:.c=.o)

SRCS_DIR = srcs

SRCS        = $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS        = $(addprefix $(SRCS_DIR)/, $(OB))

$(NAME): $(OBJS)
	cd mlx && $(MAKE) && cp libmlx.a ..
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS) libmlx.a -o $(NAME)

all: $(NAME)

clean:
	cd mlx && $(MAKE) clean
	rm -f $(OBJS)
	rm -f libmlx.a

fclean: clean
	rm -f $(NAME)

re: fclean all
