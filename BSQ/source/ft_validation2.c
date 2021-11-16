#include "ft_parse.h"
#include <stdio.h>

void	tr_map_grid(int *buffer, char c, char empty, char block)
{
	if (c == empty)
		*buffer = EMPTY;
	else if (c == block)
		*buffer = BLOCK;
}

int	validate_len(char **lines)
{
	int	i;

	i = 0;
	while (*(lines + i + 1) != NULL)
	{
		if (ft_strlen(*(lines + i + 1)) != ft_strlen(*(lines + 1)))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

int	validate_sequence(char *line)
{
	return (ft_is_printable(line)
		&& ft_strlen(line) >= 4
		&& line[0] >= '0' && line[0] <= '9');
}

int	validate_first_line(char *line)
{
	int		last;
	char	full;
	char	block;
	char	empty;

	if (!validate_sequence(line))
		return (0);
	last = ft_strlen(line) - 1;
	full = line[last];
	block = line[last - 1];
	empty = line[last - 2];
	if (full == block || full == empty || block == empty)
		return (0);
	return (1);
}
