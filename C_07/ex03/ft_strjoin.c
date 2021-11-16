/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 02:06:16 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/25 16:04:12 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_total_length(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	total_len;
	int	sep_len;

	total_len = 0;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			total_len++;
			j++;
		}
	}
	sep_len = 0;
	while (*sep++)
		sep_len++;
	return (total_len + sep_len * (size - 1));
}

int	add_sep(char *str, char *sep)
{
	int	n;

	n = 0;
	while (*sep)
	{
		*str++ = *sep++;
		n++;
	}
	return (n);
}

int	add_string(char *dest, char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		*dest++ = *str++;
		n++;
	}
	return (n);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		final_length;
	char	*str;
	char	*ptr;
	int		i;

	if (size == 0)
		return ((char *) malloc(sizeof(char)));
	final_length = get_total_length(size, strs, sep);
	str = (char *) malloc((final_length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ptr = str;
	i = -1;
	while (++i < size)
	{
		ptr += add_string(ptr, strs[i]);
		if (i != size - 1)
			ptr += add_sep(ptr, sep);
	}
	*ptr = '\0';
	return (str);
}
