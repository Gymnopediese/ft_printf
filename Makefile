NAME		= libftprintf.a
SRCS 		= ft_printf.c $(wildcard */*.c)
OBJS		= ${SRCS:.c=.o}
LIB 		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o 	:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all		: ${NAME}

$(NAME)	: ${OBJS}
		echo ${OBJS}
		ar rcs ${NAME} ${OBJS}

clean	:
		rm -f ${OBJS}
fclean	:	clean
		rm -f ${NAME}
re:		fclean all

bonus	: all

test: ${OBJS}
	${CC} main.c ${OBJS}
	./a.out