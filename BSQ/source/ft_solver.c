#include "ft_solver.h"

int			is_square_valid(t_map *map, int col, int row, int width);
void		update_result(t_solution *result, t_square temp);
t_square	create_square(int col, int row, int n);

t_solution	*solver(t_map *map)
{
	t_solution	*result;
	int			row;
	int			col;
	int			n;

	result = malloc(sizeof(t_solution));
	result->map = *map;
	result->square = create_square(0, 0, 0);
	row = 0;
	while (row < map->row)
	{
		col = 0;
		while (col < map->col)
		{
			n = 0;
			while (is_square_valid(map, col, row, n))
				n++;
			update_result(result, create_square(col, row, n - 1));
			col++;
		}
		row++;
	}
	return (result);
}

int	is_square_valid(t_map *map, int col, int row, int width)
{
	int	i_row;
	int	i_col;

	i_col = 0;
	if (col + width > map->col || row + width > map->row)
		return (0);
	while (i_col < width)
	{
		i_row = 0;
		while (i_row < width)
		{
			if (map->grid[row + i_row][col + i_col] == BLOCK)
				return (0);
			i_row++;
		}
		i_col++;
	}
	return (1);
}

t_square	create_square(int col, int row, int n)
{
	t_square	result;

	result.col = col;
	result.row = row;
	result.width = n;
	return (result);
}

void	update_result(t_solution *result, t_square temp)
{
	if (result->square.width < temp.width)
	{
		result->square = temp;
	}
}
