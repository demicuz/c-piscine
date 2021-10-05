#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*a;
	int	i;
	int	n;

	if (min >= max)
	{
		*range = NULL;
		range = NULL;
		return (0);
	}
	a = malloc(sizeof(int) * (max - min));
	*range = a;
	if (!a)
		return (-1);
	i = 0;
	n = min;
	while (n < max)
	{
		a[i] = n;
		i++;
		n++;
	}
	return (i);
}
