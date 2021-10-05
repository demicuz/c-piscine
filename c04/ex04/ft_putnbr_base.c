#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_base_len(char *base)
{
	int		i;
	int		j;

	if (!*base || !*(base + 1))
		return (-1);
	i = 0;
	while (base[i + 1])
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	if (base[i + 1] == '+' || base[i + 1] == '-')
		return (-1);
	return (i + 1);
}

void	ft_putnbr(int nb, char *base, int len)
{
	if (nb >= 0 && nb < len)
	{
		ft_putchar(base[nb]);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		if (nb <= -len)
			ft_putnbr(-(nb / len), base, len);
		ft_putnbr(-(nb % len), base, len);
	}
	else
	{
		if (nb >= len)
			ft_putnbr(nb / len, base, len);
		ft_putnbr(nb % len, base, len);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_base_len(base);
	if (base_len == -1)
		return ;
	ft_putnbr(nbr, base, base_len);
}
