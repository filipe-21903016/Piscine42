/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:01:12 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/25 20:20:09 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (is_space(*str))
		str++;
	while (is_sign(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_number(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (sign * result);
}
