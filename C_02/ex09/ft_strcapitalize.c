/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:23:08 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/09 21:01:26 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha_numeric(char c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (-1);
}

char	to_upper(char c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	return (c);
}

char	to_lower(char c)
{
	if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	return (c);
}

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		str[index] = to_lower(str[index]);
		index++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	index;

	ft_strlowcase(str);
	index = 0;
	while (str[index] != '\0')
	{
		if (index == 0)
		{
			str[index] = to_upper(str[index]);
		}
		else if (is_alpha_numeric(str[index - 1]) < 0)
		{
			str[index] = to_upper(str[index]);
		}
		index++;
	}
	return (str);
}
