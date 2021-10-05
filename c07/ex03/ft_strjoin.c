#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strcat_end(char *end, char *src)
{
	while (*src)
	{
		*end = *src;
		end++;
		src++;
	}
	*end = '\0';
	return (end);
}

char	*ft_allocate_mem(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	size_t	size_sep;
	size_t	size_all;

	size_all = 0;
	size_sep = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		size_all += ft_strlen(strs[i]);
		i++;
	}
	result = malloc(sizeof(char) * (size_all + size_sep * size + 1));
	result[0] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	char	*p;
	int		i;

	if (size <= 0)
	{
		result = malloc(sizeof(char));
		if (result)
			result[0] = '\0';
		return (result);
	}
	result = ft_allocate_mem(size, strs, sep);
	p = result;
	i = 0;
	if (result)
	{
		while (i < size)
		{
			p = ft_strcat_end(p, strs[i]);
			if (i != size - 1)
				p = ft_strcat_end(p, sep);
			i++;
		}
	}
	return (result);
}
