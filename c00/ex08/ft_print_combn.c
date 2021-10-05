#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_buffer(int buffer[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(buffer[i] + '0');
		i++;
	}
}

int	ft_check_if_terminal(int buffer[], int n)
{
	int	i;
	int	flag;
	int	digit;

	i = n - 1;
	flag = 1;
	digit = 9;
	while (i >= 0)
	{
		if (buffer[i] != digit)
		{
			flag = 0;
			break ;
		}
		else
		{
			digit--;
			i--;
		}
	}
	return (flag);
}

void	ft_recur(int buffer[], int n, int i)
{
	int	j;

	if (i == n)
	{
		ft_print_buffer(buffer, n);
		if (!ft_check_if_terminal(buffer, n))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		return ;
	}
	if (i == 0)
		j = 0;
	else
		j = buffer[i - 1] + 1;
	while (j <= 9)
	{
		buffer[i] = j;
		ft_recur(buffer, n, i + 1);
		j++;
	}
}

void	ft_print_combn(int n)
{
	int	buffer[10];

	ft_recur(buffer, n, 0);
}
