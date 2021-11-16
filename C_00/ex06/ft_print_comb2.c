/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:08:03 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/05 16:54:28 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(int a, int b, int c, int d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a == 57 && b == 56 && c == 57 && d == 57)
	{
		return ;
	}
	write(1, ", ", 2);
}

void	four_digit_loop(int *a, int *b, int *c, int *d)
{
	*a = 48;
	while (*a <= 57)
	{
		*b = 48;
		while (*b <= 57)
		{
			*c = 48;
			while (*c <= 57)
			{
				*d = 48;
				while (*d <= 57)
				{
					if (*a * 10 + *b < *c * 10 + *d)
					{
						print_numbers(*a, *b, *c, *d);
					}
					(*d)++;
				}
				(*c)++;
			}
			(*b)++;
		}
		(*a)++;
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	four_digit_loop(&a, &b, &c, &d);
}
