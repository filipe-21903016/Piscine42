/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:42:36 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/09 22:45:59 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_print(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (-1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_char_hex(int c)
{
	int		x;
	int		index;
	char	hex[2];
	char	*hex_chars;

	hex_chars = "0123456789abcdef";
	x = c;
	index = 0;
	while (x)
	{
		*(hex + index) = *(hex_chars + (x % 16));
		x /= 16;
		index++;
	}
	if (index < 2)
	{
		write(1, "0", 1);
	}
	index--;
	while (index >= 0)
	{
		write(1, hex + index, 1);
		index--;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_print(str[index]) > 0 )
		{
			ft_putchar(str[index]);
		}
		else
		{
			ft_putchar('\\');
			print_char_hex(str[index]);
		}
		index++;
	}
}
