/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 20:25:46 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/26 20:42:11 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < length - 1)
	{
		j = 0;
		while (j < length - i - 1)
		{
			if ((*f)(tab[j], tab[j + 1]) > 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
