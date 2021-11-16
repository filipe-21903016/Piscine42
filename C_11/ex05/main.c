/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 20:44:52 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/26 21:27:57 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	do_op(int v1, int v2, char op)
{
	if (op == '/' && v2 != 0)
		ft_putnbr(v1 / v2);
	if (op == '+')
		ft_putnbr(v1 + v2);
	if (op == '-')
		ft_putnbr(v1 - v2);
	if (op == '*')
		ft_putnbr(v1 * v2);
	if (op == '%' && v2 != 0)
		ft_putnbr(v1 % v2);
	if (op == '/')
		ft_putstr("Stop : division by zero\n");
	if (op == '%')
		ft_putstr("Stop : modulo by zero\n");
	ft_putstr("\n");
}

int	is_valid_op(char *str)
{
	if (ft_strlen(str) == 1)
	{
		if (*str == '+'
			|| *str == '-'
			|| *str == '%'
			|| *str == '/'
			|| *str == '*')
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int		v1;
	int		v2;
	char	op;

	if (argc == 4)
	{
		if (!is_valid_op(argv[2]))
		{
			write(1, "0", 1);
			return (0);
		}
		op = argv[2][0];
		v1 = ft_atoi(argv[1]);
		v2 = ft_atoi(argv[3]);
		do_op(v1, v2, op);
	}
	return (0);
}

