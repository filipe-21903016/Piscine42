/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:03:51 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/08 19:07:47 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_x_y_char(int i, int j, int x, int y)
{
	if (i == 0 && j == 0 || i == x - 1 && j == y - 1)
	{
		ft_putchar('A');
	}
	else if (i == x - 1 && j == 0 || i == 0 && j == y - 1)
	{
		ft_putchar('C');
	}
	else if (i == 0 || j == 0 || i == x - 1 || j == y - 1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	j;
	int	i;

	if (x < 1 || y < 1)
	{
		return ;
	}
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			print_x_y_char(i, j, x, y);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
