NAME		= fractol
CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -MMD

HEADER		= includes/fractol.h

SRCS		= 	srcs/main.c \
				srcs/utils.c \
				srcs/error.c \
				srcs/burning_ship.c \
				srcs/drop.c \
				srcs/julia.c \
				srcs/lambada.c \
				srcs/mandelbrot.c \
				srcs/spider.c \
				srcs/cameramiving.c \

OBJS		= $(SRCS: .c=.o)

$(NAME):		$(OBJS)
				cd minilibx && $(MAKE) && mv libmlx.a ../libmlx.a
				$(CC) $(CFLAGS) -I $(HEADERS) $(OBJS) libmlx.a -o $(NAME)

all:			$(NAME)

.c.o:
				$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $<

$(OBJS):		$(HEADERS)

clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS:.o=.d)

fclean:			clean
				cd minilibx && $(MAKE) clean
				$(RM) libmlx.a
				$(RM) $(OBJS)

re:				fclean all

.PHONY:			all clean fclean re

.SILENT:
