/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:59:13 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/10 01:16:13 by fzarco-l         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	dest_len;

	dest_len = get_str_len(dest);
	index = 0;
	while (*(src + index) != '\0')
	{
		*(dest + index + dest_len) = *(src + index);
		index++;
	}
	*(dest + index + dest_len) = *(src + index);
	return (dest);
}
