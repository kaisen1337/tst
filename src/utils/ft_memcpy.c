#include "minishell.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*arr1;
	unsigned const char	*arr2;
	size_t				i;

	if ((!dest && !src) || n == 0)
		return (dest);
	arr1 = dest;
	arr2 = src;
	i = 0;
	while (i < n)
	{
		arr1[i] = arr2[i];
		i++;
	}
	return (dest);
}
