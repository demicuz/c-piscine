int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str >= ' ' && *str <= '~')
		{
			str++;
		}
		else
			return (0);
	}
	return (1);
}
