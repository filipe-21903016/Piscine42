/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:25:34 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/21 19:56:45 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_file.h"
#include "ft_string.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char	*filename;
	char	*value;
	int		parsed_value;
	int		fd;
	char 	*buffer;

	filename = (char *) malloc(BUFFER_SIZE * sizeof(char *));
	ft_strcpy(filename, "numbers.dict");
	value = argv[1];
	if (argc == 3)
	{
		free(filename);
		filename = argv[1];
		value = argv[2];
	}
	parsed_value = ft_atoi(value);
	if (parsed_value < 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	fd = open(filename , O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error\n");
		return (0);
	}

	buffer = readlines(fd);
	int count = count_lines(buffer);
	printf("%d\n", count);
	return (0);
}
