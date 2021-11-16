/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:19:51 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/09 23:15:03 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	if (size > 0)
	{
		while (src[count] != '\0')
		{
			count++;
		}
		while ((unsigned int) index < size - 1 && src[index] != '\0')
		{
			*(dest + index) = *(src + index);
			index++;
		}
		*(dest + index) = '\0';
	}
	return (count);
}
