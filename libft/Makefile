
SRCS = ft_isalnum.c ft_split.c ft_putchar_fd.c ft_itoa.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_isprint.c ft_strdup.c ft_calloc.c ft_memcpy.c ft_strlcat.c ft_strnstr.c ft_isalpha.c ft_memmove.c ft_memccpy.c ft_strlcpy.c ft_strrchr.c ft_atoi.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlen.c ft_tolower.c ft_bzero.c ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strncmp.c ft_toupper.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c
BONUS_OBJ = ${BONUS:.c=.o}
OBJ = ${SRCS:.c=.o}
HEADER = -I libft.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc
.c.o:		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
RM = rm -f
NAME	=	libft.a
$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
all:		${NAME}
clean:
			${RM} ${OBJ} $(BONUS_OBJ)

fclean:     clean
			$(RM) $(NAME)
re:			fclean all
bonus:		$(OBJ) $(BONUS_OBJ)
			ar rc $(NAME) $(OBJ) $(BONUS_OBJ)
			ranlib $(NAME)
