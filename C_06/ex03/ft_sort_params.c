/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:05:36 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/12 20:00:20 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap_ptr(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_putstr(char *str)
{
	int		index;
	char	c;

	index = 0;
	while (str[index] != '\0')
	{
		c = str[index];
		write(1, &c, 1);
		index++;
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

void	ft_sort_strs(char **strs, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < argc)
		{
			if (ft_strcmp(strs[j], strs[i]) > 0)
			{
				ft_swap_ptr(strs + j, strs + i);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort_strs(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
}
