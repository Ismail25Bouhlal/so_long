CC= gcc
FLAGS=  -c -Wall -Werror -Wextra
NAME= libftprintf.a
HRADER= ft_printf.h
SRC= ft_printf.c   ft_put.c     ft_putchar.c ft_putnbr.c  ft_putstr.c ft_hex.c ft_hexmin.c ft_pointer.c ft_unsigned_int.c
OBJ= ${SRC:.c=.o}

${NAME} : ${OBJ} ${HEADER}
	@${CC} ${FLAGS} ${SRC}
	@ar -rc ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all

all: ${NAME}
