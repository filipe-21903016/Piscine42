#include "ft_parse.h"
#include <stdio.h>

int	count_lines(char **lines)
{
	int	i;

	i = 0;
	while (*(lines + i) != NULL)
		i++;
	return (i);
}

int	validate_grid(char **lines, char empty, char block)
{
	int	x;
	int	y;

	y = 0;
	lines++;
	while (*(lines + y) != NULL)
	{
		x = 0;
		while (x < ft_strlen(*lines))
		{
			if (lines[y][x] != empty && lines[y][x] != block)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	**make_grid(char **lines, t_map map)
{
	int	col;
	int	row;
	int	**grid;
	int	*buffer;

	grid = (int **) malloc(map.row * sizeof (int *));
	row = -1;
	while (++row < map.row)
	{
		buffer = (int *) malloc(map.col * sizeof(int));
		col = -1;
		while (++col < map.col)
		{
			tr_map_grid(buffer + col, lines[row][col], map.empty, map.block);
		}
		*(grid + row) = buffer;
	}
	return (grid);
}

void	destroy_grid(t_map map)
{
	int	row;

	row = 0;
	while (row < map.row)
	{
		free(map.grid[row]);
		row++;
	}
}

char	*fill_chars(t_map *map, char *str)
{
	int	len;

	len = ft_strlen(str);
	map->full = str[len - 1];
	map->block = str[len - 2];
	map->empty = str[len - 3];
	str[len - 3] = '\0';
	return (str);
}
