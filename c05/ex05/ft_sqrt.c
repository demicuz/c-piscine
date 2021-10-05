int	ft_sqrt(int nb)
{
	int	result;

	if (nb <= 0)
		return (0);
	result = 1;
	while (nb / result > result)
	{
		result++;
	}
	if (nb % result == 0 && nb / result == result)
		return (result);
	return (0);
}
