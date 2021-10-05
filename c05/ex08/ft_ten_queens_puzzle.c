#include <unistd.h>

int	g_n = 0;

void	ft_print_queens(int queens[])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = queens[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_valid_place(int queens[], int i, int j)
{
	int	cnt;
	int	queen_j;

	cnt = 0;
	while (cnt < i)
	{
		queen_j = queens[cnt];
		if (queen_j == j)
			return (0);
		if (queen_j == j - (i - cnt))
			return (0);
		if (queen_j == j + (i - cnt))
			return (0);
		cnt++;
	}
	return (1);
}

void	recur(int queens[], int i)
{
	int	j;

	if (i == 10)
	{
		ft_print_queens(queens);
		g_n++;
		return ;
	}
	j = 0;
	while (j < 10)
	{
		if (ft_valid_place(queens, i, j))
		{
			queens[i] = j;
			recur(queens, i + 1);
		}
		j++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];

	recur(queens, 0);
	return (g_n);
}
