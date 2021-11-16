/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:37:42 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/25 23:31:17 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include <stdio.h>

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] != (void *)0)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	free_map(t_map *map)
{
	free(map->grid);
	free(map);
}

t_map	*parse_map(char *file_content)
{
	t_map	*map;
	char	**lines;
	char	*temp;

	map = (t_map *) malloc(sizeof(t_map));
	lines = ft_split(file_content, "\n");
	if (count_lines(lines) > 2 && validate_first_line(*lines)
		&& validate_len(lines))
	{
		temp = fill_chars(map, *lines);
		if (validate_grid(lines, map->empty, map->block))
		{
			map->row = ft_atoi(temp);
			if (map-> row && count_lines(lines) - 1 == map->row)
			{
				map->col = ft_strlen(*(lines + 1));
				map->grid = make_grid(lines + 1, *map);
				free_lines(lines);
				return (map);
			}
		}
	}
	free_lines(lines);
	free_map(map);
	return (NULL);
}
