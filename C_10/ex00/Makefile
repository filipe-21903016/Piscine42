all: ft_display_file

ft_display_file: ft_display_file.o ft_putchar.o ft_putstr.o
	gcc ft_display_file.o ft_putchar.o ft_putstr.o -o ft_display_file

ft_display_file.o: ft_display_file.c ft.h
	gcc -Wall -Wextra -Werror -c ft_display_file.c

ft_putchar.o: ft_putchar.c ft.h
	gcc -Wall -Wextra -Werror -c ft_putchar.c

ft_putstr.o: ft_putstr.c ft.h
	gcc -Wall -Wextra -Werror -c ft_putstr.c

clean:
	rm -f *.o

fclean: clean
	rm -f ft_display_file
