#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*result;
	unsigned int	i;
	int				n;

	if (min >= max)
		return ((void *) 0);
	result = malloc(sizeof(int) * ((long long int) max - (long long int) min));
	if (result)
	{
		i = 0;
		n = min;
		while (n < max)
		{
			result[i] = n;
			i++;
			n++;
		}
	}
	return (result);
}
