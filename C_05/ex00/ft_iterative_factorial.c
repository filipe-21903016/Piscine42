/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:15:21 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/16 15:41:51 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	max;
	int	factorial;

	factorial = 1;
	if (nb == 0)
	{
		return (factorial);
	}
	if (nb > 0)
	{
		max = nb;
		while (max > 0)
		{
			factorial = factorial * max;
			max--;
		}
		return (factorial);
	}
	return (0);
}
