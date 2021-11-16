/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 04:34:58 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/22 05:06:14 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft.h"
#define READ_ERR "Cannot read file.\n"
#define MANY_ARGS "Too many arguments.\n"
#define FEW_ARGS "File name missing.\n"
#define BUF_SIZE 10

int	main(int argc, char **argv)
{
	int		fd;
	int		n;
	char	buffer[BUF_SIZE + 1];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr(READ_ERR);
			return (0);
		}
		n = read(fd, buffer, BUF_SIZE);
		while (n)
		{
			buffer[n] = '\0';
			ft_putstr(buffer);
			n = read(fd, buffer, BUF_SIZE);
		}
		close(fd);
	}
	if (argc == 1)
		ft_putstr(FEW_ARGS);
	if (argc > 2)
		ft_putstr(MANY_ARGS);
	return (0);
}
