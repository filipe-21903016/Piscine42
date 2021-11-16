/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:25:23 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/21 19:56:48 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	count_lines(char *str)
{
	int count;
	int	i;
	
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (i != 1 && str[i] == '\n' && str[i - 1] != '\n')
		{
			count++;
		}
		i++;
	}
	return (count);
}