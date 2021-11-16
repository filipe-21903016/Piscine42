/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 01:11:58 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/15 16:15:32 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_up(int *skyscraper, int *input)
{
	int	x;
	int	y;
	int	biggest;
	int	count;

	x = 0;
	while (x < 4)
	{
		biggest = 0;
		y = 0;
		count = 0;
		while (y < 4)
		{
			if (get_value(skyscraper, x, y) > biggest)
			{
				biggest = get_value(skyscraper, x, y);
				count++;
			}
			y++;
		}
		if (count != *(input + x))
			return (0);
		x++;
	}
	return (1);
}

int	check_down(int *skyscraper, int *input)
{
	int	x;
	int	y;
	int	biggest;
	int	count;

	x = 0;
	while (x < 4)
	{
		count = 0;
		y = 3;
		biggest = 0;
		while (y >= 0)
		{
			if (get_value(skyscraper, x, y) > biggest)
			{
				biggest = get_value(skyscraper, x, y);
				count++;
			}
			y--;
		}
		if (count != *(input + x + 4))
			return (0);
		x++;
	}
	return (1);
}

int	check_left(int *skyscraper, int *input)
{
	int	x;
	int	y;
	int	biggest;
	int	count;

	y = 0;
	while (y < 4)
	{
		biggest = 0;
		x = 0;
		count = 0;
		while (x < 4)
		{
			if (get_value(skyscraper, x, y) > biggest)
			{
				biggest = get_value(skyscraper, x, y);
				count++;
			}
			x++;
		}
		if (count != *(input + y))
			return (0);
		y++;
	}
	return (1);
}

int	check_right(int *skyscraper, int *input)
{
	int	x;
	int	y;
	int	biggest;
	int	count;

	y = 0;
	while (y < 4)
	{
		biggest = 0;
		x = 3;
		count = 0;
		while (x >= 0)
		{
			if (get_value(skyscraper, x, y) > biggest)
			{
				biggest = get_value(skyscraper, x, y);
				count++;
			}
			x--;
		}
		if (count != *(input + y + 4))
			return (0);
		y++;
	}
	return (1);
}

int	is_char_valid(char c, int i)
{
	if (i % 2 == 0 && c >= '1' && c <= '4')
		return (1);
	if (i % 2 != 0 && c == ' ')
		return (1);
	return (0);
}
