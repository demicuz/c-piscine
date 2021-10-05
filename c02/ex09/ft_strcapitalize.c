int	ft_is_alphanumeric(char c)
{
	if ((c >= 'A' && c <= 'Z') || ((c >= 'a' && c <= 'z')))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*t;
	char	is_word;

	t = str;
	is_word = 0;
	while (*str)
	{
		if (is_word && (*str >= 'A' && *str <= 'Z'))
		{
			*str = *str + 32;
		}
		else if (!is_word && (*str >= 'a' && *str <= 'z'))
		{
			*str = *str - 32;
		}
		if (ft_is_alphanumeric(*str))
			is_word = 1;
		else
			is_word = 0;
		str++;
	}
	return (t);
}
