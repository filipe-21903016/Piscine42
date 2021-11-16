/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 11:55:19 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/06 12:50:45 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
void	ft_rev_int_tab(int *tab, int size)
{
	int	first;
	int	last;
	int	temp;

	first = 0;
	last = size - 1;
	while (first < last)
	{
		temp = *(tab + first);
		*(tab + first) = *(tab + last);
		*(tab + last) = temp;
		first++;
		last--;
	}
}
