/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:40:48 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/22 03:14:58 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

int	ft_putchar_helper(int nb, char *p_str)
{
	unsigned int	x;
	int				counter1;

	x = nb;
	counter1 = 0;
	if (nb < 0)
	{
		x = -1 * nb;
	}
	while (x)
	{
		*p_str = '0' + x % 10;
		p_str++;
		x /= 10;
		counter1++;
	}
	return (counter1);
}

void	ft_putnbr(int nb)
{
	char			str[10];
	char			*p_str;
	int				c;

	p_str = str;
	c = ft_putchar_helper(nb, p_str);
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	while (c > 0)
	{
		write(1, str + c - 1, 1);
		c--;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) != '\0' || *(s2 + i) != 0)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			if (*(s1 + i) > *(s2 + i))
			{
				return (1);
			}
			else
			{
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

void	ft_show_tab(struct s_stock_str *par)
{
	if (par == NULL)
		return ;
	while (par->str)
	{
		ft_putstr(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		write(1, "\n", 1);
		par++;
	}
}
