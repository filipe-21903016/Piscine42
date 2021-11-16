/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:33:54 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/18 02:42:38 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_base_valid(char *base)
{
	int	index;
	int	j;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-' || is_space(base[index]))
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if (j != index && base[j] == base[index])
				return (0);
			j++;
		}
		index++;
	}
	if (index < 2)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	base_len;

	base_len = ft_strlen(base);
	sign = 1;
	result = 0;
	if (!is_base_valid(base))
		return (0);
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_base(*str, base) > -1)
	{
		result *= base_len;
		result += is_base(*str, base);
		str++;
	}
	return (sign * result);
}
