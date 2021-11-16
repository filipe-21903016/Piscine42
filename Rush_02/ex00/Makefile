rush-02: rush_02.o ft_file.o ft_string.o ft_stdlib.o
	gcc -Wall -Wextra -Werror *.o -o rush-02

rush02.o: rush_02.c
	gcc -c rush_02.c 

ft_file.o: ft_file.c ft_file.h
	gcc -c ft_file.c

ft_string.o: ft_string.c ft_string.h
	gcc -c ft_string.c

ft_stdlib.o: ft_stdlib.c ft_stdlib.h
	gcc -c ft_stdlib.c

fclean:
	rm *.o *.h.gch rush-02

clean:
	rm *.o *.h.gch
