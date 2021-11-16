/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:53:39 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/07 13:33:09 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	return (-1);
}

int	ft_str_is_lowercase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_lowercase(str[index]) < 0)
		{
			return (0);
		}
		index++;
	}
	return (1);
}
