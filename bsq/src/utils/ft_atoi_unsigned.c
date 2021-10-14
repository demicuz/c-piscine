#include "utils/ft_isspace.h"

unsigned int	ft_atoi_unsigned(char *str)
{
	unsigned int	result;

	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}
