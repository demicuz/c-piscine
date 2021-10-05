int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_base_len(char *base)
{
	int		i;
	int		j;

	if (!*base || !*(base + 1))
		return (-1);
	i = 0;
	while (base[i + 1])
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	if (base[i + 1] == '+' || base[i + 1] == '-')
		return (-1);
	return (i + 1);
}

int	ft_index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, int len)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_index_of(base, *str) != -1)
	{
		result *= len;
		result += ft_index_of(base, *str) * sign;
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;

	base_len = ft_base_len(base);
	if (base_len == -1)
		return (0);
	return (ft_atoi(str, base, base_len));
}
