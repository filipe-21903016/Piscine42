/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fhandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:16:44 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/25 23:38:48 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fhandler.h"

void	init_vars2(char *last, int *buff_size, char **buffer)
{
	*last = '\0';
	*buff_size = 1;
	*buffer = malloc(*buff_size * sizeof(char));
	*buffer[0] = '\0';
}

void	ft_puterr(char *str, int size)
{
	write(2, str, size);
}

char	*read_file(int fd)
{
	char	*buffer;
	char	temp[2];
	char	last;
	char	current;
	int		buff_size;

	init_vars2(&last, &buff_size, &buffer);
	while (1)
	{
		read(fd, &current, 1);
		if (current == '\n' && last == '\n')
			break ;
		else
		{
			buff_size++;
			buffer = ft_realloc(buffer, buff_size);
			temp[0] = current;
			temp[1] = '\0';
			ft_strcat(buffer, temp);
			last = current;
		}
	}
	return (buffer);
}
