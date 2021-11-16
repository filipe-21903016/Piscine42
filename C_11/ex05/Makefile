NAME = do-op
SRCS = ft_atoi.c ft_putnbr.c ft_putstr.c ft_strlen.c main.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

${NAME}: $(OBJS) 
	$(CC) $(OBJS) -o $(NAME)

all: ${NAME}

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: .c.o all clean fclean re
