void	ft_ultimate_div_mod(int *a, int *b)
{
	int	t;

	t = *a;
	*a = t / *b;
	*b = t % *b;
}
