/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:15:46 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/22 19:02:32 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	get_len(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	is_base_valid(char *base)
{
	int	index;
	int	j;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
		{
			return (-1);
		}
		j = 0;
		while (base[j] != '\0')
		{
			if (j != index && base[j] == base[index])
			{
				return (-1);
			}
			j++;
		}
		index++;
	}
	return (1);
}

void	print_int_base_recursive(unsigned int n, char *base)
{
	int	base_len;

	base_len = get_len(base);
	if (n >= 0 && n < (unsigned int) base_len)
	{
		ft_putchar(base[n]);
		return ;
	}
	print_int_base_recursive(n / base_len, base);
	ft_putchar(base[n % base_len]);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	n;

	n = nbr;
	base_len = get_len(base);
	if (base_len > 1 && is_base_valid(base) > 0)
	{
		if (nbr < 0)
		{
			n = -1 * nbr;
			ft_putchar('-');
		}
		print_int_base_recursive(n, base);
	}
}
