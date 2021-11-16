/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:25:28 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/21 19:57:16 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_file.h"

char	*readlines(int fd)
{
	char	*buffer;
	int		n;

	buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
	while ((n = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[n] = '\0';
	}
	close(fd);
	return (buffer);
}


t_node	*create_dict(char *str)
{
	t_node	*ptr;
		
}
