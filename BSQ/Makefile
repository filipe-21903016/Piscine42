NAME = bsq

SRCS = \
source/bsq.c \
source/ft_parse.c \
source/ft_solver.c \
source/ft_print_solution.c \
source/ft_atoi.c \
source/ft_fhandler.c \
source/ft_split.c \
source/ft_strlen.c \
source/ft_strcat.c \
source/ft_putstr.c \
source/ft_realloc.c \
source/ft_validation.c \
source/ft_validation2.c

OBJS = $(SRCS:.c=.o)

TESTS = __tests__/ft_generate_map.c __tests__/solver.spec.c

FLAGS = -Wall -Wextra -Werror

DFLAG = -g

LOG = valgrind-out.txt

LOG_DIR = *.dSYM

MEMFLAGS = --leak-check=full \
		   --show-leak-kinds=all \
		   --track-origins=yes \
		   --log-file=$(LOG)

VAL = valgrind

CC = gcc

INCLUDE = includes

RM = rm -f

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I$(INCLUDE)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(LOG)

fclean: clean
	$(RM) $(NAME)

re: fclean all

memcheck: all
	$(VAL) $(MEMFLAGS) ./$(NAME) valgrind_test.txt

memclean: fclean
	$(RM) -r $(LOG) $(LOG_DIR)

.PHONY: all .c.o clean fclean re
