void	ft_rev_int_tab(int *tab, int size)
{
	int	c;
	int	t;

	c = 0;
	while (c < size / 2)
	{
		t = tab[c];
		tab[c] = tab[size - 1 - c];
		tab[size - 1 - c] = t;
		c++;
	}
}
