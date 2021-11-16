/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:50:58 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/15 15:53:34 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"

void	set_value(int *skyscraper, int col, int row, int value)
{
	*(skyscraper + col + 4 * row) = value;
}

int	is_in_col(int *skyscraper, int row, int value)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (get_value(skyscraper, x, row) == value)
			return (1);
		x++;
	}
	return (0);
}

int	is_in_row(int *skyscraper, int col, int value)
{
	int	y;

	y = 0;
	while (y < 4)
	{
		if (get_value(skyscraper, col, y) == value)
			return (1);
		y++;
	}
	return (0);
}

int	is_valid_guess(int *skyscraper, int col, int row, int value)
{
	if (is_in_row(skyscraper, col, value) == 0
		&& is_in_col(skyscraper, row, value) == 0)
	{
		return (1);
	}
	return (0);
}

int	is_correct_order(int *skyscraper, int *input)
{
	return ((check_up(skyscraper, input)
			&& check_down(skyscraper, input)
			&& check_left(skyscraper, input + 8)
			&& check_right(skyscraper, input + 8)));
}
