/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:58:20 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/22 15:46:06 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

struct s_stock_str	*ft_str_to_struct(char *str)
{
	char				*copy;
	int					length;
	struct s_stock_str	*s_str;

	length = ft_strlen(str);
	copy = (char *) malloc(length * sizeof(char) + 1);
	s_str = (struct s_stock_str *) malloc(sizeof(struct s_stock_str));
	ft_strcpy(copy, str);
	s_str -> size = length;
	s_str -> copy = copy;
	s_str -> str = str;
	return (s_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*strs;
	int					i;
	t_stock_str			*last;
	struct s_stock_str	*temp;

	last = (t_stock_str *) malloc(sizeof(t_stock_str));
	last->str = NULL;
	i = 0;
	strs = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	if (strs == NULL)
		return (NULL);
	while (i < ac)
	{
		temp = ft_str_to_struct(av[i]);
		*(strs + i) = *temp;
		free(temp);
		i++;
	}
	*(strs + i) = *last;
	free(last);
	return (strs);
}
