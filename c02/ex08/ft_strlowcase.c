char	*ft_strupcase(char *str)
{
	char	*t;

	t = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str + 32;
		}
		str++;
	}
	return (t);
}
