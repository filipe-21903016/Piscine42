/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:32:56 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/26 21:42:53 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_ptr(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
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

void ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (ft_strcmp(tab[j], tab[i]) > 0)
			{
				ft_swap_ptr(tab + j, tab + i);
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>
int main(int argc, char **argv)
{
	argc++;
	ft_sort_string_tab(argv + 1);
	while (*argv)
	{
		printf("%s\n", *argv);
		argv++;
	}
}
