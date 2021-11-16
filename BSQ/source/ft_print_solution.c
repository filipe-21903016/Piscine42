#include "ft_print_solution.h"

void	print_solution(t_solution *solution)
{
	int	i;
	int	j;

	i = 0;
	while (i < solution->map.row)
	{
		j = 0;
		while (j < solution->map.col)
		{
			if (
				i >= solution->square.row
				&& i < (solution->square.row + solution->square.width)
				&& j >= solution->square.col
				&& j < (solution->square.col + solution->square.width))
				write(1, &solution->map.full, 1);
			else if (solution->map.grid[i][j] == BLOCK)
				write(1, &solution->map.block, 1);
			else if (solution->map.grid[i][j] == EMPTY)
				write(1, &solution->map.empty, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
