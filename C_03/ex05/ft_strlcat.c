/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 02:09:14 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/10 13:46:39 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_len(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	remaining_size;
	unsigned int	dest_len;
	unsigned int	copy_len;
	unsigned int	src_len;

	src_len = get_len(src);
	remaining_size = size;
	while (*dest != '\0')
	{
		dest++;
		remaining_size--;
	}
	dest_len = size - remaining_size;
	if (dest_len < remaining_size)
	{
		copy_len = remaining_size - 1;
		if (src_len < copy_len)
		{
			copy_len = src_len;
		}
		ft_strncpy(dest, src, copy_len);
		dest[copy_len] = '\0';
	}
	return (dest_len + src_len);
}
