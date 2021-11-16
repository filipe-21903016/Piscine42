/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:59:06 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/07 15:34:32 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	to_upper(char c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	return (c);
}

char	*ft_strupcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		str[index] = to_upper(str[index]);
		index++;
	}
	return (str);
}
