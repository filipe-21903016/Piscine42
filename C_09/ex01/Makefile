NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADERS = includes 
RM = rm -f
LIBC = ar rc
LIBR = ranlib

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${HEADERS}

${NAME}: ${OBJS} 
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: .c.o all clean fclean re
