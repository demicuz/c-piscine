int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			result++;
		i++;
	}
	return (result);
}
