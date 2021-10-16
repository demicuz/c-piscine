int	ft_compare(char *str, char *to_find)
{
	while (*str && *to_find)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (*to_find == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		if (ft_compare(str, to_find))
			return (str);
		str++;
	}
	return ((char *) 0);
}
