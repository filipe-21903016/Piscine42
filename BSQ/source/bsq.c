/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:13:32 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/25 23:29:29 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_core.h"
#include "ft_lib.h"
#include "ft_solver.h"
#include "ft_parse.h"
#include "ft_fhandler.h"
#include "ft_print_solution.h"
#include "ft_realloc.h"

void	init_vars(char *last, int *buff_size, char **buffer)
{
	*last = '\0';
	*buff_size = 1;
	*buffer = malloc(*buff_size * sizeof(char));
	*buffer[0] = '\0';
}

char	*get_input(void)
{
	char	*buffer;
	char	temp[2];
	char	last;
	char	current;
	int		buff_size;

	init_vars(&last, &buff_size, &buffer);
	while (1)
	{
		read(0, &current, 1);
		if (current == '\n' && last == '\n')
			break ;
		else
		{
			buff_size++;
			buffer = ft_realloc(buffer, buff_size);
			temp[0] = current;
			temp[1] = '\0';
			ft_strcat(buffer, temp);
			last = current;
		}
	}
	return (buffer);
}

void	handle_stdin(void)
{
	t_map		*map;
	t_solution	*solution;
	char		*str;

	str = get_input();
	if (ft_strlen(str) > 0)
	{
		map = parse_map(str);
		if (map != NULL)
		{
			solution = solver(map);
			print_solution(solution);
			free(solution);
		}
		else
			ft_puterr(MAP_ERROR, MAP_ERROR_SIZE);
		destroy_grid(*map);
		free(map->grid);
		free(map);
		free(str);
	}
	else
		ft_puterr(MAP_ERROR, MAP_ERROR_SIZE);
}

void	handle_file(int fd)
{
	t_map		*map;
	t_solution	*solution;
	char		*str;

	if (fd != -1)
	{
		str = read_file(fd);
		map = parse_map(str);
		if (map != NULL)
		{
			solution = solver(map);
			print_solution(solution);
			free(solution);
			destroy_grid(*map);
			free(map->grid);
		}
		else
			ft_puterr(MAP_ERROR, MAP_ERROR_SIZE);
		free(map);
		free(str);
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	int			i;

	if (argc == 1)
		handle_stdin();
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			handle_file(fd);
			close(fd);
			if (i < argc - 1)
			{
				write(1, "\n", 1);
			}
			i++;
		}
	}
	return (0);
}
