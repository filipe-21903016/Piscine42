/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 20:40:38 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/16 15:51:40 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	index--;
	if (index < 1)
	{
		write(1, "0", 1);
	}
	while (index >= 0)
	{
		write(1, hex + index, 1);
		index--;
	}
}

void	print_str(char *str, int size)
{
	int	index;

	index = 0;
	while (index < size && *(str + index) != '\0')
	{
		if (*(str + index) >= 32 && *(str + index) <= 127)
		{
			write(1, str + index, 1);
		}
		else
		{
			write(1, ".", 1);
		}
		index++;
	}
}

void	print_mem_addr_hex(void *addr)
{
	uintptr_t		ptr;
	int				index;
	char			hex[16];
	char			*hex_chars;

	hex_chars = "0123456789abcdef";
	ptr = (uintptr_t) addr;
	index = 0;
	while (index < 16)
	{
		hex[index] = '0';
		index++;
	}
	index--;
	while (ptr)
	{
		*(hex + index) = *(hex_chars + (ptr % 16));
		ptr /= 16;
		index--;
	}
	print_str(hex, 16);
}

void	print_str_hex(char *str, int size)
{
	int	index;
	int	j;

	index = 0;
	while (index < size)
	{
		j = 0;
		while (j < 2)
		{
			if (*(str + index) == '\0')
			{
				write(1, " ", 1);
			}
			else
			{
				print_char_hex(*(str + index));
			}
			index++;
			j++;
		}
		write(1, " ", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				index;
	char			*ptr;

	if (size > 0)
	{
		ptr = (char *) addr;
		index = 0;
		while ((unsigned int) index < size)
		{
			print_mem_addr_hex(addr + index);
			write(1, ":", 1);
			write(1, " ", 1);
			print_str_hex(addr + index, 16);
			print_str(addr + index, 16);
			write(1, "\n", 1);
			index += 16;
		}
	}
	return (addr);
}
