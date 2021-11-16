/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:51:53 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/16 19:51:34 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_input_valid(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != 31)
		return (0);
	while (str[i] != '\0')
	{
		if (!is_char_valid(str[i], i))
			return (0);
		i++;
	}
	return (1);
}

int	*split_str(char *str)
{
	int	*input;
	int	i;
	int	j;

	i = 0;
	j = 0;
	input = (int *) malloc(16 * sizeof(int));
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			input[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (input);
}

int	solve(int *skyscraper, int *input)
{
	int	i;
	int	col;
	int	row;

	col = 0;
	row = 0;
	i = 1;
	while (i < 5)
	{
		if (!find_next_empty(skyscraper, &col, &row)
			&& is_correct_order(skyscraper, input))
		{
			return (1);
		}
		if (is_valid_guess(skyscraper, col, row, i))
		{
			set_value(skyscraper, col, row, i);
			if (solve(skyscraper, input))
				return (1);
			set_value(skyscraper, col, row, 0);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*input;
	int	*skyscraper;

	if (argc == 2 && is_input_valid(argv[1]))
	{
		skyscraper = get_skyscraper(4, 4);
		input = split_str(argv[1]);
		if (solve(skyscraper, input))
		{
			print_skyscraper(skyscraper, 4, 4);
			free(skyscraper);
			free(input);
			return (0);
		}
		free(skyscraper);
		free(input);
	}
	ft_putstr("Error\n");
	return (1);
}
