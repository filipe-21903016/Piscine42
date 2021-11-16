#ifndef FT_CORE_H
# define FT_CORE_H
# define EMPTY 0
# define BLOCK -1
# define FULL 1
# define MAP_ERROR "map error\n"
# define MAP_ERROR_SIZE 10
# define BUF_SIZE 4096
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_square
{
	int	col;
	int	row;
	int	width;
}	t_square;

typedef struct s_map
{
	int		col;
	int		row;
	char	empty;
	char	full;
	char	block;
	int		**grid;
}	t_map;

typedef struct s_solution
{
	t_map		map;
	t_square	square;
}	t_solution;

#endif
