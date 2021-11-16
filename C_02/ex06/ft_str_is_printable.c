/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:23:04 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/09 20:52:30 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_print(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (-1);
}

int	ft_str_is_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_print(str[index]) < 0)
		{
			return (0);
		}
		index++;
	}
	return (1);
}
