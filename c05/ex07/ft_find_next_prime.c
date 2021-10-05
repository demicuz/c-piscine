int	ft_is_prime(int nb)
{
	int	n;

	if (nb <= 1)
		return (0);
	n = 2;
	while (n <= nb / 2)
	{
		if (nb % n == 0)
			return (0);
		else
			n++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	n;

	if (nb <= 2)
		return (2);
	n = nb;
	while (!ft_is_prime(n))
		n++;
	return (n);
}
