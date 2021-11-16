/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:16:41 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/10 01:30:18 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_str_len(char *str)
{
	int	count;

	count = 0;
	while (*(str + count) != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	index;
	int	dest_len;

	dest_len = get_str_len(dest);
	index = 0;
	while (*(src + index) != '\0' && (unsigned int) index < nb)
	{
		*(dest + index + dest_len) = *(src + index);
		index++;
	}
	*(dest + index + dest_len) = '\0';
	return (dest);
}
