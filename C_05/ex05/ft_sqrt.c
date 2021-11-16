/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:07:36 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/16 18:23:19 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	start;
	int	end;
	int	mid;

	start = 0;
	end = nb;
	if (nb == 1)
		return (1);
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid <= nb / mid)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}
