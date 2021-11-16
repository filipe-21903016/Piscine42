/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:05:26 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/15 15:53:00 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	initialize_skyscraper(int *skyscraper, int width, int height)
{
	int	x;	
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			*(skyscraper + x + y * width) = 0;
			x++;
		}
		y++;
	}
}

int	*get_skyscraper(int width, int height)
{
	int	*skyscraper;

	skyscraper = (int *) malloc(width * height * sizeof(int));
	initialize_skyscraper(skyscraper, width, height);
	return (skyscraper);
}

void	print_skyscraper(int *skyscraper, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_putchar(*(skyscraper + j + i * width) + '0');
			if (j != width - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	get_value(int *skyscraper, int col, int row)
{
	return (*(skyscraper + col + row * 4));
}

int	find_next_empty(int *skyscraper, int *col, int *row)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (get_value(skyscraper, x, y) == 0)
			{
				*col = x;
				*row = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
