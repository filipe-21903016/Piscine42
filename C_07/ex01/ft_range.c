/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:26:08 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/22 02:05:24 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*vector;
	int	i;
	int	size;

	size = max - min;
	if (size <= 0)
		return ((void *) 0);
	vector = (int *) malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		vector[i] = min;
		min++;
		i++;
	}
	return (vector);
}
