NAME		= fractol
CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -MMD

HEADER		= includes/fractol.h

SRCS		= 	srcs/main.c
				srcs/mlxfunctions.c

OBJS		= $(SRCS: .c=.o)

$(NAME):		$(OBJS)
				cd minilibx && $(MAKE) && mv libmlx.dylib ../libmlx.dylib
				$(CC) $(CPPFLAGS) -I $(HEADERS) $(OBJS) libmlx.dylib -o $(NAME)

all:			$(NAME)

.c.o:
				$(CC) $(CPPFLAGS) -I $(HEADERS) -o $@ -c $<

$(OBJS):		$(HEADERS)

clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS:.o=.d)

fclean:			clean
				cd minilibx && $(MAKE) clean
				$(RM) libmlx.dylib
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re