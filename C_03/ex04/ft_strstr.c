/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzarco-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:32:52 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/11 11:50:01 by fzarco-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while ((unsigned int) i < n && (*(s1 + i) != '\0' || *(s2 + i) != '\0'))
	{
		if (*(s1 + i) != *(s2 + i))
		{
			if (*(s1 + i) > *(s2 + i))
			{
				return (1);
			}
			else
			{
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

int	get_len(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	needle_len;

	needle_len = get_len(to_find);
	if (needle_len == 0)
	{
		return (str);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (ft_strncmp(str + i, to_find, needle_len) == 0)
			{
				return (str + i);
			}
		}
		i++;
	}
	return ((void *)0);
}
