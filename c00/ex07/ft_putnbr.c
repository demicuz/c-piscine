#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb <= 9)
		ft_putchar('0' + nb);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-(nb / 10));
		ft_putnbr(-(nb % 10));
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
