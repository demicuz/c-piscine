char	*ft_strupcase(char *str)
{
	char	*t;

	t = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str - 32;
		}
		str++;
	}
	return (t);
}
