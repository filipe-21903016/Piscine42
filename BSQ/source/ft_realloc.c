#include "ft_realloc.h"
#include "ft_lib.h"
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

void	*ft_realloc(void *ptr, size_t size)
{
	char	*ptr1;
	size_t	old_size;

	if (ptr == 0)
		return (malloc(size));
	old_size = ft_strlen((char *)ptr) + 1;
	if (size <= old_size)
		return (ptr);
	ptr1 = malloc(size);
	ft_memcpy(ptr1, ptr, size);
	free(ptr);
	return (ptr1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*dest_char;
	unsigned const char	*src_char;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	while (i < n)
	{
		*((char *)dest_char + i) = *((char *)src_char + i);
		i++;
	}
	return (dest_char);
}
