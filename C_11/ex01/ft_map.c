/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:37:33 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/26 19:51:26 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*buffer;

	if (length > 0)
	{
		i = 0;
		buffer = malloc(length * sizeof(int));
		if (buffer == NULL)
			return (NULL);
		while (i < length)
		{
			buffer[i] = (*f)(tab[i]);
			i++;
		}
		return (buffer);
	}
	return (NULL);
}
