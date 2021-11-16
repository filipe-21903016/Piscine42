/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:20:23 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/22 19:18:10 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_putnbr_base(int nbr, char *base);
void	n_to_base(unsigned int n, char *base, char *dest);
int		is_base_valid(char *base);
int		get_len(char *str);
int		is_space(char c);

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

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	base_len;

	base_len = get_len(base);
	sign = 1;
	result = 0;
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_to_int;

	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (NULL);
	base_to_int = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(base_to_int, base_to));
}
