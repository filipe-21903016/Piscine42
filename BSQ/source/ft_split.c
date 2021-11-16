/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:54:22 by fzarco-l          #+#    #+#             */
/*   Updated: 2021/08/25 21:25:44 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (*charset++ == c)
			return (1);
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			words++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (words);
}

char	*allocate_word(char *str, char *charset)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != '\0' && !is_sep(str[i], charset))
		i++;
	word = (char *) malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] != '\0' && !is_sep(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**args;
	int		i;
	char	*temp;

	args = (char **) malloc((count_words(str, charset) + 1) * sizeof(char *));
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			temp = allocate_word(str, charset);
			args[i++] = temp;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	args[i] = NULL;
	return (args);
}
