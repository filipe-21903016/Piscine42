/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:15:41 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/07 13:37:30 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_uppercase(char c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (-1);
}

int	ft_str_is_uppercase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_uppercase(str[index]) < 0)
		{
			return (0);
		}
		index++;
	}
	return (1);
}
