/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:33:39 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/12 13:38:58 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	power_result;

	power_result = 1;
	i = 0;
	if (power < 0)
	{
		return (0);
	}
	while (i < power)
	{
		power_result *= nb;
		i++;
	}
	return (power_result);
}
