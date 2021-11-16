#include <stdlib.h>

int	get_len(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
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
	return (1);
}

void	n_to_base(unsigned int n, char *base, char *dest)
{
	int		base_len;
	int		i;
	int		j;
	char	temp;

	base_len = get_len(base);
	j = 0;
	while (n)
	{
		*(dest + j) = base[n % base_len];
		n /= base_len;
		j++;
	}
	*(dest + j) = '\0';
	i = 0;
	j--;
	while (i < j)
	{
		temp = *(dest + i);
		*(dest + i++) = *(dest + j);
		*(dest + j--) = temp;
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	n;
	char			*str;

	n = (unsigned int) nbr;
	base_len = get_len(base);
	str = (char *) malloc(33 * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (base_len > 1 && is_base_valid(base))
	{
		if (nbr < 0)
		{
			str[0] = '-';
			n = -1 * nbr;
			n_to_base(n, base, str + 1);
		}
		else if (n == 0)
			str[0] = base[0];
		else
			n_to_base(n, base, str);
		return (str);
	}
	return (NULL);
}
