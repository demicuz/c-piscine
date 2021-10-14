#include "utils/ft_isspace.h"

char	*ft_skip_atoi(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}
